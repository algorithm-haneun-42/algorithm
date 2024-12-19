import java.io.*;
import java.util.*;

public class BootcampOfTaesang {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < n + 1; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int[] dp = new int[n + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			dp[a] += k;
			if (b != n) dp[b + 1] -= k;
		}
		for (int i = 1; i <= n; i++) {
			dp[i] += dp[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			System.out.print(arr[i] + dp[i] + " ");
		}
	}
}
