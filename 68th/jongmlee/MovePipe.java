import java.io.*;
import java.util.*;

public class MovePipe {
	static int n;
	static int[][] map;
	static int[][] dp;
	static int[][][] dir = {{{0, -1}, {0, -2}}, {{-1, -1}, {-1, -2}}, {{-1, 0}, {-2, 0}}, {{-1, -1}, {-2, -1}}, {{0, -1}, {-1, -2}}, {{-1, 0}, {-2, -1}}, {{-1, -1}, {-2, -2}}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dp = new int[n][n];
		dp[0][0] = 1;
		dp[0][1] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					solve(i, j);
				}
			}
		}
		System.out.println(Arrays.deepToString(dp));
		System.out.println(dp[n - 1][n - 1]);
	}
	static void solve(int x, int y) {
		for (int i = 0; i < dir.length; i++) {
				int nx1 = x + dir[i][0][0];
				int ny1 = y + dir[i][0][1];
				if (nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= n || map[nx1][ny1] == 1) continue;
				int nx2 = x + dir[i][1][0];
				int ny2 = y + dir[i][1][1];
				if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n || map[nx2][ny2] == 1) continue;
				dp[x][y] += Math.min(dp[nx1][ny1], dp[nx2][ny2]);
		}
	}
}
