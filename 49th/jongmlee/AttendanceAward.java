import java.io.*;
import java.util.*;

public class AttendanceAward {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][][] dp = new int[n + 1][2][3];
		dp[1][0][0] = 1;
		dp[1][1][0] = 1;
		dp[1][0][1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i][0][0] = dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] % 1000000;
			dp[i][0][1] = dp[i - 1][0][0] % 1000000;
			dp[i][0][2] = dp[i - 1][0][1] % 1000000;
			dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % 1000000;
			dp[i][1][1] = dp[i - 1][1][0] % 1000000;
			dp[i][1][2] = dp[i - 1][1][1] % 1000000;
		}
		System.out.println((dp[n][0][0]
		+ dp[n][0][1]
		+ dp[n][0][2]
		+ dp[n][1][0]
		+ dp[n][1][1]
		+ dp[n][1][2]) % 1000000);
	}
}
