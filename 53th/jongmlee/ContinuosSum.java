import java.io.*;
import java.util.*;

public class ContinuosSum {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		int[][] dp = new int[n][2];
		for (int i = 0 ; i < n ; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		dp[0][0] = arr[0];
		int max = arr[0];
		for (int i = 1; i < n; i++) {
				dp[i][0] = Math.max(arr[i], dp[i - 1][0] + arr[i]);
				dp[i][1] = Math.max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
			max = Math.max(Math.max(dp[i][0], dp[i][1]), max);
		}
		System.out.println(max);
	}
}
