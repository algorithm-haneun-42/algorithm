import java.util.*;
import java.io.*;

public class Wall2206 {
	static int n, m;
	static int ans = -1;
	static int[][] map;
	static boolean[][][] v;
	static Queue<Pos> q = new LinkedList<>();
	static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		v = new boolean[n][m][2];
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = line.charAt(j) - '0';
			}
		}
		v[0][0][0] = true;
		q.add(new Pos(0, 0, 1, 0));
		bfs();
		System.out.println(ans);
	}
	static void bfs() {
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			if (cur.x == n - 1 && cur.y == m - 1) {
				ans = cur.c;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (map[nx][ny] == 0 && !v[nx][ny][cur.isCrash]) {
						v[nx][ny][cur.isCrash] = true;
						q.add(new Pos(nx, ny, cur.c + 1, cur.isCrash));
					} else if (map[nx][ny] == 1 && cur.isCrash == 0 && !v[nx][ny][1]) {
						v[nx][ny][1] = true;
						q.add(new Pos(nx, ny, cur.c + 1, 1));
					}
				}
			}
		}
	}
	static class Pos {
		int x;
		int y;
		int c;
		int isCrash;
		Pos(int x, int y, int c, int isCrash) {
			this.x = x;
			this.y = y;
			this.c = c;
			this.isCrash = isCrash;
		}
	}
}
