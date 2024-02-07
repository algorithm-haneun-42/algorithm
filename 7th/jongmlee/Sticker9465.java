import java.util.*;

public class Sticker9465 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		while (t-- > 0) {
			int n = sc.nextInt();
			int[][] sticker = new int[2][n + 1];
			for (int i = 0; i < 2; i++) {
				for (int j = 1; j <= n; j++) {
					sticker[i][j] = sc.nextInt();
				}
			}
			int[][] dp = new int[2][n + 1];
			dp[0][1] = sticker[0][1];
			dp[1][1] = sticker[1][1];
			if (n == 1) {
				System.out.println(Math.max(dp[0][1], dp[1][1]));
				continue;
			}
			dp[0][2] = dp[1][1] + sticker[0][2];
			dp[1][2] = dp[0][1] + sticker[1][2];
			for (int i = 3; i <= n; i++) {
				dp[0][i] = Math.max(dp[1][i - 1], Math.max(dp[0][i - 2], dp[1][i - 2])) + sticker[0][i];
				dp[1][i] = Math.max(dp[0][i - 1], Math.max(dp[1][i - 2], dp[0][ i - 2])) + sticker[1][i];
			}
			System.out.println(Math.max(dp[0][n], dp[1][n]));
		}
	}
}
