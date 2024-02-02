import java.util.*;


public class Safe2468 {
	static int[][] map;
	static boolean[][] v;
	static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	static int n, max, cnt, answer;
	static Queue<Pos> q;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = sc.nextInt();
				max = Math.max(map[i][j], max);
			}
		}
		answer = 0;
		for (int k = 0; k <= max; k++) {
			cnt = 0;
			solve(k);
			answer = Math.max(answer, cnt);
		}
		System.out.println(answer);
	}
	public static void solve(int k) {
		v = new boolean[n][n];
		q = new LinkedList<>();
		for (int i = 0 ; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > k && !v[i][j]) {
					v[i][j] = true;
					q.add(new Pos(i, j));
					bfs(k);
					cnt++;
				}
			}
		}
	}
	public static void bfs(int k) {
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			for (int i = 0; i < dir.length; i++) {
				int newX = cur.x + dir[i][0];
				int newY = cur.y + dir[i][1];
				if (newX >= 0 && newX < n && newY >= 0 && newY < n && !v[newX][newY] && map[newX][newY] > k) {
					v[newX][newY] = true;
					q.add(new Pos(newX, newY));
				}
			}
		}
	}
	static class Pos{
		int x;
		int y;
		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
