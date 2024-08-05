import java.io.*;
import java.util.*;

public class RescuePrincess {
	static class Pos {
		int x, y, w;
		boolean gram;
		public Pos(int x, int y, int w, boolean gram) {
			this.x = x;
			this.y = y;
			this.w = w;
			this.gram = gram;
		}
		public String toString() {
			return "x = " + this.x + ", y = " + this.y + ", w = " + this.w + ", gram = " + this.gram;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		boolean[][][] v = new boolean[n][m][2];
		int[][] dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		Queue<Pos> q = new LinkedList<>();
		v[0][0][0] = true;
		q.add(new Pos(0, 0, 0, false));
		boolean flag = false;
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			//System.out.println(cur);
			if (cur.w > t) {
				break;
			}
			if (cur.x == n - 1 && cur.y == m - 1) {
				flag = true;
				System.out.println(cur.w);
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (!cur.gram && v[nx][ny][0]) continue;
				if (cur.gram && v[nx][ny][1]) continue;
				if (!cur.gram && map[nx][ny] == 1) continue;
				if (!cur.gram) {
					v[nx][ny][0] = true;
					if (map[nx][ny] == 2) {
						q.add(new Pos(nx, ny, cur.w + 1, true));
					} else {
						q.add(new Pos(nx, ny, cur.w + 1, cur.gram));
					}
				} else {
					v[nx][ny][1] = true;
					q.add(new Pos(nx, ny, cur.w + 1, cur.gram));
				}
			}
		}
		if (!flag) {
			System.out.println("Fail");
		}
	}
}
