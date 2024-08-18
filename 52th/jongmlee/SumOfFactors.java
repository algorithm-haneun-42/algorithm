import java.io.*;
import java.util.*;

public class SumOfFactors {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long[] dp = new long[1000001];
		Arrays.fill(dp, 1);
		for (int i = 2; i < dp.length; i++) {
			for (int j = 1; i * j < dp.length; j++) {
				dp[i * j] += i;
			}
			dp[i] += dp[i - 1];
		}
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < t; i++) {
			sb.append(dp[Integer.parseInt(br.readLine())]).append('\n');
		}
		System.out.println(sb);
	}
}
