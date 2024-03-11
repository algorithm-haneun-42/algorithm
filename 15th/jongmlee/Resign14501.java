import java.io.*;
import java.util.*;

public class Resign14501 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int t[] = new int[n + 15];
		int p[] = new int[n + 15];
		int dp[] = new int[n + 15];
		int max = 0;
		StringTokenizer st;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			t[i] = Integer.parseInt(st.nextToken());
			p[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i <= n; i++) {
			dp[i] = Math.max(dp[i], max); 
			dp[t[i] + i] = Math.max(dp[t[i] + i], p[i] + dp[i]);
			max = Math.max(max, dp[i]);
		}
		System.out.println(max);
	}
}
