import java.util.*;

public class Tomato7569 {
	static class Tomato {
		int x;
		int y;
		int z;
		int d;
		Tomato(int x, int y, int z, int d) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.d = d;
		}
	}
	static int box[][][];
	static int dir[][] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int h = sc.nextInt();
		box = new int[h][n][m];
		Queue<Tomato> q = new LinkedList<>();
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					box[i][j][k] = sc.nextInt();
					if (box[i][j][k] == 1) {
						q.add(new Tomato(i, j, k, 0));
					}
				}
			}
		}
		if (q.size() == h * m * n) {
			System.out.println(0);
			return;
		}
		int max = 0;
		while (!q.isEmpty()) {
			Tomato cur = q.poll();
			for (int i = 0; i < 6; i++) {
				int newX = cur.x + dir[i][0];
				int newY = cur.y + dir[i][1];
				int newZ = cur.z + dir[i][2];
				if (newX < 0 || newX >= h || newY < 0 || newY >= n || newZ < 0 || newZ >= m) {
					continue;
				}
				if (box[newX][newY][newZ] == 0) {
					box[newX][newY][newZ] = 1;
					max = Math.max(cur.d + 1, max);
					q.add(new Tomato(newX, newY, newZ, cur.d + 1));
				}
			}
		}
		int flag = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (box[i][j][k] == 0) {
						flag = 1;
						break ;
					}
				}
			}
		}
		if (flag == 1)
			System.out.println(-1);
		else
			System.out.println(max);
	}
}
