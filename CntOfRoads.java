import java.io.*;
import java.util.*;

public class CntOfRoads {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()) + 1;
		int m = Integer.parseInt(st.nextToken()) + 1;
		int k = Integer.parseInt(br.readLine());
		List<int[]> broken = new ArrayList<>();
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			broken.add(new int[4]);
			for (int j = 0; j < 4; j++) {
				broken.get(i)[j] = Integer.parseInt(st.nextToken()) + 1;
			}
		}
		long[][] dp = new long[n + 1][m + 1];
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				boolean flag1 = false; // 왼쪽
				boolean flag2 = false; // 위
				for (int s = 0; s < k; s++) {
					int[] cur = broken.get(s);
					if (((i == cur[0] && j - 1 == cur[1]) && (i == cur[2] && j == cur[3]))
						|| ((i == cur[2] && j - 1 == cur[3]) && (i == cur[0] && j == cur[1]))) {
						flag1 = true;
					}
					if ((i == cur[0] && j == cur[1]) && (i - 1 == cur[2] && j == cur[3])
						|| ((i == cur[2] && j == cur[3]) && (i - 1== cur[0] && j == cur[1]))) {
						flag2 = true;
					}
					//if (i == n && j == m) {
					//	System.out.println(cur[0] + " " + cur[1] + " " + cur[2] + " " + cur[3]);
					//}
				}
				if (!flag1) dp[i][j] += dp[i][j - 1];
				if (!flag2) dp[i][j] += dp[i - 1][j];
			}
		}
		//for (int i = 1; i <= n; i++) {
		//	System.out.println(Arrays.toString(dp[i]));
		//}
		System.out.println(dp[n][m]);
	}
}
