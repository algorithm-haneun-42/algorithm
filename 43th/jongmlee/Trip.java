import java.io.*;
import java.util.*;

public class Trip {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n + 1][n + 1];
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			if (from > to) continue;
			int w = Integer.parseInt(st.nextToken());
			arr[from][to] = Math.max(w, arr[from][to]);
		}
		int[][] dp = new int[n + 1][m + 1];
		for (int i = 2; i < n + 1; i++) {
			if (arr[1][i] != 0) dp[i][2] = arr[1][i];
		}
		for (int i = 2; i < m; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (dp[j][i] != 0) {
					for (int z = j + 1; z < n + 1; z++) {
						if (arr[j][z] != 0) {
							dp[z][i + 1] = Math.max(dp[z][i + 1], dp[j][i] + arr[j][z]);
						}
					}
				}
			}
		}
		System.out.println(Arrays.deepToString(dp));
		int answer = 0;
		for (int i = 1; i < m + 1; i++) {
			answer = Math.max(answer, dp[n][i]);
		}
		System.out.println(answer);
	}
}
