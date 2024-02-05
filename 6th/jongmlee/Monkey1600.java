import java.io.*;
import java.util.*;

public class Monkey1600 {
	static int n, m, k;
	static int[][] map;
	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	static int[][] nDir = {{-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
	static boolean[][][] v;
	static Queue<Pos> q = new LinkedList<>();
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		k = sc.nextInt();
		m = sc.nextInt();
		n = sc.nextInt();
		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		v = new boolean[k + 1][n][m];
		v[k][0][0] = true;
		q.add(new Pos(0, 0, 0, k));
		System.out.println(bfs());
	}
	static int bfs() {
		while(!q.isEmpty()) {
			Pos cur = q.poll();
			if (cur.x == n - 1 && cur.y == m - 1) {
				return cur.c;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0 && !v[cur.mk][nx][ny]) {
					v[cur.mk][nx][ny] = true;
					q.add(new Pos(nx, ny, cur.c + 1, cur.mk));
				}
			}
			if (cur.mk > 0) {
				for (int i = 0; i < 8; i++) {
					int nx = cur.x + nDir[i][0];
					int ny = cur.y + nDir[i][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0 && !v[cur.mk - 1][nx][ny]) {
						v[cur.mk - 1][nx][ny] = true;
						q.add(new Pos(nx, ny, cur.c + 1, cur.mk - 1));
					}
				}
			}
		}
		return -1;
	}
	static class Pos {
		int x;
		int y;
		int c;
		int mk;
		Pos(int x, int y, int c, int mk) {
			this.x = x;
			this.y = y;
			this.c = c;
			this.mk = mk;
		}
	}
}
