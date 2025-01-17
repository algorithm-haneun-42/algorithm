import java.io.*;
import java.nio.Buffer;
import java.util.*;

public class BuildFarm {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] farm = new int[n + 1][m + 1];
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= m; j++) {
				farm[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[][] dp = new int[n + 1][m + 1];
		int max = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (farm[i][j] != 0) continue;
				int min = Math.min(dp[i][j - 1], dp[i - 1][j]);
				if (min <= dp[i - 1][j - 1]) {
					dp[i][j] = min + 1;
				} else {
					dp[i][j] = min;
				}
				max = Math.max(dp[i][j], max);
			}
		}

		System.out.println(max);
	}
}
