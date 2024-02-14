import java.io.*;
import java.util.*;

public class Coin2294 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		int[] dp = new int[k + 1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		Arrays.sort(arr);
		if (k < arr[0]) {
			System.out.println(-1);
			return;
		}
		for (int i = 0; i < arr[0]; i++) dp[i] = -1;
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[j] > i) break;
				if (i == arr[j]) {
					dp[i] = 1;
					continue;
				}
				if (dp[i - arr[j]] == -1) continue;
				dp[i] = Math.min((dp[i - arr[j]] + 1), dp[i]);
			}
			if (dp[i] == Integer.MAX_VALUE) dp[i] = -1;
		}
		System.out.println(dp[k]);
	}
}
