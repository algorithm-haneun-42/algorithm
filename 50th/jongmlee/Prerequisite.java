import java.io.*;
import java.util.*;

public class Prerequisite {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] indeed = new int[n + 1];
		int[] dp = new int[n + 1];
		List<Integer>[] graph = new ArrayList[n + 1];
		Arrays.fill(graph, new ArrayList<>());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			indeed[to]++;
			graph[from].add(to);
		}
		for (int i = 1; i <= n; i++) {
			if (indeed[i] == 0) {
				dp[i] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int tmp = graph[i].get(j);
				dp[tmp] = Math.max(dp[tmp], dp[i] + 1);
			}
		}
		for (int i = 1; i <= n; i++) {
			System.out.print(dp[i] + " ");
		}
	}
}
