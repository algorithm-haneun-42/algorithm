import java.io.*;

public class LCS9251 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String l1 = br.readLine();
		String l2 = br.readLine();
		int[][] dp = new int[l1.length() + 1][l2.length() + 1];
		for (int i = 1; i <= l1.length(); i++) {
			for (int j = 1; j <= l2.length(); j++) {
				if (l1.charAt(i - 1) == l2.charAt(j - 1)) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		System.out.println(dp[l1.length()][l2.length()]);
	}
}
