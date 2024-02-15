import java.io.*;
import java.util.*;

class MakeBridge2146 {
	static StringTokenizer st;
	static int n;
	static int[][] map;
	static boolean[][] v;
	static Queue<Pos> q = new LinkedList<>();
	static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		for (int i = 0 ; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		numbering();
		int min = Integer.MAX_VALUE;
		for (int i = 0 ; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0 && checkEdge(i, j)) {
					min = Math.min(findNearestIsland(i, j), min);
				}
			}
		}
		System.out.println(min);
	}
	static int findNearestIsland(int x, int y) {
		q.clear();
		v = new boolean[n][n];
		int num = map[x][y];
		q.add(new Pos(x, y, 0));
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			if (checkIsland(cur.x, cur.y, num)) {
				return cur.c;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 0 && !v[nx][ny]) {
					v[nx][ny] = true;
					q.add(new Pos(nx, ny, cur.c + 1));
				}
			}
		}
		return Integer.MAX_VALUE;
	}
	static boolean checkIsland(int x, int y, int num) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != 0 && map[nx][ny] != num) {
				return true;
			}
		}
		return false;
	}
	static boolean checkEdge(int x, int y) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 0) {
				return true;
			}
		}
		return false;
	}
	static void numbering() {
		int num = 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					map[i][j] = num;
					q.add(new Pos(i, j, 0));
					while (!q.isEmpty()) {
						Pos cur = q.poll();
						for (int k = 0; k < 4; k++) {
							int nx = cur.x + dir[k][0];
							int ny = cur.y + dir[k][1];
							if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 1) {
								map[nx][ny] = num;
								q.add(new Pos(nx, ny, 0));
							}
						}
					}
					num++;
				}
			}
		}
	}
	static class Pos{
		int x;
		int y;
		int c;
		Pos (int x, int y, int c) {
			this.x = x;
			this.y = y;
			this.c = c;
		}
	}
}