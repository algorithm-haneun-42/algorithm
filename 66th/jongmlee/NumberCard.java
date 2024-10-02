import java.io.*;
import java.util.*;

public class NumberCard {
	static String s;
	static int answer;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		int n = s.length();
		int[] dp = new int[n + 1];
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			int oneDigit = s.charAt(i - 1) - '0';
			if (oneDigit >= 1 && oneDigit <= 9) {
				dp[i] += dp[i - 1];
			}
			if (i > 1) {
				int twoDigits = (s.charAt(i - 2) - '0') * 10 + (s.charAt(i - 1) - '0');
				if (twoDigits >= 10 && twoDigits <= 34) {
					dp[i] += dp[i - 2];
				}
			}
		}
		System.out.println(dp[n]);
	}
}
