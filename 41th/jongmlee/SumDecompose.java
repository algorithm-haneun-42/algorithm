import java.io.*;
import java.util.*;

public class SumDecompose {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		long[][] dp = new long[n + 1][k + 1];
		Arrays.fill(dp[0], 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				for (int s = i; s >= 0; s--) {
					dp[i][j] += dp[s][j - 1] % 1000000000;
				}
				dp[i][j] %= 1000000000;
			}
		}
		//System.out.println(Arrays.deepToString(dp));
		System.out.println(dp[n][k]);
	}
}
