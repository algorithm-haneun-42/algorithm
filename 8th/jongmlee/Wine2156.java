import java.util.*;
import java.io.*;

public class Wine2156 {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] wine = new int[n + 1];
		int[] dp = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			wine[i] = Integer.parseInt(br.readLine());
		}
		for (int i = 1; i <= n; i++) {
			if (i == 1) dp[i] = wine[i];
			else if (i == 2) dp[i] = wine[i - 1] + wine[i];
			else if (i == 3) dp[i] = Math.max(Math.max(wine[i - 2] + wine[i], wine[i - 1] + wine[i]), dp[i - 1]);
			else dp[i] = Math.max(Math.max((wine[i - 1] + wine[i] + dp[i - 3]), dp[i - 2] + wine[i]), dp[i - 1]);
		}
		System.out.println(Math.max(dp[n], dp[n - 1]));
	}
}
