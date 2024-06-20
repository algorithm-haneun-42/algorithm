import java.io.*;
import java.util.*;

public class Work {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int dp[] = new int[n];
		int answer = 0;
		
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int time = Integer.parseInt(st.nextToken());
			int degree = Integer.parseInt(st.nextToken());
			dp[i] = time;
			for(int j = 0; j < degree; j++) {
				int f = Integer.parseInt(st.nextToken()) - 1;
				dp[i] = Math.max(dp[i], dp[f] + time);
			}
			answer = Math.max(answer, dp[i]);
		}
		System.out.println(answer);
	}
}
