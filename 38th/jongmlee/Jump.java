import java.io.*;
import java.util.*;

public class Jump {
	static final int INF = 10000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		int[] dp = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.fill(dp, INF);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= arr[i]; j++) {
				if (i + j < n) {
					dp[i + j] = Math.min(dp[i] + 1, dp[i + j]);
				}
			}
		}
		if (dp[n - 1] == INF) {
			System.out.println(-1);
		} else {
			System.out.println(dp[n - 1]);
		}
	}
}
