import java.io.*;
import java.util.*;

public class ConnectedElementsCnt {
	static List<List<Integer>> graph;
	static boolean[] v;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		graph = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			graph.get(from).add(to);
			graph.get(to).add(from);
		}
		v = new boolean[n + 1];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				v[i] = true;
				dfs(i);
				ans++;
			}
		}
		System.out.println(ans);
	}

	private static void dfs(int x) {
		graph.get(x).forEach(e -> {
			if (!v[e]) {
				v[e] = true;
				dfs(e);
			}
		});
	}
}
