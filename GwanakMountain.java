import java.io.*;
import java.util.*;

public class GwanakMountain {
	public static int[] dp;
	public static List<Integer>[] graph;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] heights = new int[n + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			heights[i] = Integer.parseInt(st.nextToken());
		}
		graph = new List[n + 1];
		Arrays.fill(graph, new ArrayList<>());
		boolean[] indegree = new boolean[n + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (heights[a] < heights[b]) {
				graph[a].add(b);
				indegree[b] = true;
			} else {
				graph[b].add(a);
				indegree[a] = true;
			}
		}
		dp = new int[n + 1];

		// 진입 노드가 0개면 시작 지점
		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) {
				dfs(i);
			}
		}
	}

	private static void dfs(int cur) {
		int len = graph[cur].size();

	}
}
