import java.io.*;
import java.util.*;

public class Criboard {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n <= 6) {
			System.out.println(n);
			return;
		}
		long[] dp = new long[n + 1];
		for (int i = 1; i < n + 1; i++) {
			if (i <= 6) {
				dp[i] = i;
			} else {
				for (int j = 2; j <= 5; j++) {
					dp[i] = Math.max(dp[i - (j + 1)] * j, dp[i]);
				}
			}
		}
		System.out.println(dp[n]);
	}
}
