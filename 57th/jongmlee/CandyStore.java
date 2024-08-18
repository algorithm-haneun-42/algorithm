import java.io.*;
import java.util.*;

public class CandyStore {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = (int)(Double.parseDouble(st.nextToken()) * 100 + 0.5);
		while (n != 0) {
			int[] cal = new int[n];
			int[] cost = new int[m];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				cal[i] = Integer.parseInt(st.nextToken());
				cost[i] = (int)(Double.parseDouble(st.nextToken()) * 100 + 0.5);
			}
			int[] dp = new int[m + 1];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m + 1; j++) {
					int diff = j - cost[i];
					if (diff >= 0) {
						dp[j] = Math.max(dp[j], dp[diff] + cal[i]);
					}
				}
			}
			System.out.println(dp[m]);

			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = (int)(Double.parseDouble(st.nextToken()) * 100 + 0.5);
		}
	}
}
