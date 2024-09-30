	import java.io.*;
	import java.util.*;

	public class RemainSum {
		public static void main(String args[]) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			long answer = 0;
			long[] pSum = new long[n + 1];
			long[] cnt = new long[m];
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i < n + 1; i++) {
				pSum[i] = (pSum[i - 1] + Integer.parseInt(st.nextToken())) % m;
				if (pSum[i] == 0) answer++;
				cnt[(int)pSum[i]]++;
			}
			for (int i = 0; i < m; i++) {
				if (cnt[i] > 1) {
					answer += (cnt[i] * (cnt[i] - 1)) / 2;
				}
			}
			System.out.println(answer);
		}
	}
