import java.io.*;
import java.util.*;

public class Subject {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[][] items = new int[k][2];
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			items[i][0] = Integer.parseInt(st.nextToken());
			items[i][1] = Integer.parseInt(st.nextToken());
		}
		int[][] dp = new int[k + 1][n + 1];
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (items[i - 1][1] > j) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = Math.max(dp[i - 1][j], items[i - 1][0] + dp[i - 1][j - items[i - 1][1]]);
				}
			}
		}
		System.out.println(dp[k][n]);
	}
}
