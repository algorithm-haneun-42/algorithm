import java.util.*;
import java.io.*;

public class Iceberg2573 {
	static int n, m, cnt;
	static int year = 0;
	static int[][] map;
	static boolean[][] v;
	static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	static Queue<Ice> q = new LinkedList<>();
	static Queue<Ice> spare = new LinkedList<>();
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		while (true) {
			v = new boolean[n][m];
			cnt = 0;
			boolean flag = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] != 0 && !v[i][j]) {
						flag = true;
						v[i][j] = true;
						q.add(new Ice(i, j, getMeltAmount(i, j)));
						bfs();
						cnt++;
					}
				}
			}
			if (!flag) {
				System.out.println(0);
				return;
			}
			if (cnt >= 2) {
				System.out.println(year);
				return;
			}
			while (!spare.isEmpty()) {
				Ice cur = spare.poll();
				map[cur.x][cur.y] = map[cur.x][cur.y] - cur.c < 0 ? 0 : map[cur.x][cur.y] - cur.c;
			}
			year++;
		}
	}
	static void bfs() {
		while (!q.isEmpty()) {
			Ice cur = q.poll();
			spare.add(cur);
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 0 && !v[nx][ny]) {
					v[nx][ny] = true;
					q.add(new Ice(nx, ny, getMeltAmount(nx, ny)));
				}
			}
		}
	}
	static int getMeltAmount(int x, int y) {
		int ret = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0) {
				ret++;
			}
		}
 		return ret;
	}
	static class Ice {
		int x;
		int y;
		int c;
		Ice(int x, int y, int c) {
			this.x = x;
			this.y = y;
			this.c = c;
		}
	}
}
