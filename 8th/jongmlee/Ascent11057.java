import java.util.*;
import java.io.*;

class Ascent11057 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if (n == 1) {
			System.out.println(10);
			return;
		}
		int[] dp = new int[10];
		for (int i = 0; i < 10; i++) {
			dp[i] = i + 1;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j < 10; j++) {
				dp[j] = ((dp[j - 1] % 10007) + dp[j] % 10007) % 10007;
			}
		}
		System.out.println(dp[9]);
	}
}