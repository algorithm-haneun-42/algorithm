import java.io.*;
import java.util.*;

public class CardGame {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			int[] cards = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for (int i = 0; i < n; i++) {
				cards[i] = Integer.parseInt(st.nextToken());
			}
			int[][] dp = new int[n][n];
			int[][] sum = new int[n][n];

			for (int i = 0; i < n; i++) {
				sum[i][i] = cards[i];
				for (int j = i + 1; j < n; j++) {
					sum[i][j] = sum[i][j - 1] + cards[j];
				}
			}
			
			for (int i = 0; i < n; i++) {
				dp[i][i] = cards[i];
			}
			
			for (int len = 2; len <= n; len++) {
				for (int i = 0; i <= n - len; i++) {
					int j = i + len - 1;
					dp[i][j] = Math.max(
						cards[i] + (sum[i + 1][j] - dp[i + 1][j]), 
						cards[j] + (sum[i][j - 1] - dp[i][j - 1])
					);
				}
			}
			
			sb.append(dp[0][n - 1]).append("\n");
		}
		
		System.out.print(sb);
	}
}