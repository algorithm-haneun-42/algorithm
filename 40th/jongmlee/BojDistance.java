import java.io.*;
import java.util.*;

public class BojDistance {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String street = br.readLine();
		int[] dp = new int[n];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] == Integer.MAX_VALUE) continue;
			for (int j = i + 1; j < n; j++) {
				if (street.charAt(i) == 'B' && street.charAt(j) == 'O') {
					dp[j] = Math.min(dp[j], dp[i] + ((j - i) * (j - i)));
				} else if (street.charAt(i) == 'O' && street.charAt(j) == 'J') {
					dp[j] = Math.min(dp[j], dp[i] + ((j - i) * (j - i)));
				} else if (street.charAt(i) == 'J' && street.charAt(j) == 'B') {
					dp[j] = Math.min(dp[j], dp[i] + ((j - i) * (j - i)));
				}
			}
		}
		System.out.println(dp[n - 1] == Integer.MAX_VALUE ? -1 : dp[n - 1]);
	}
}
