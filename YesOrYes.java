import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;
import java.util.*;

public class YesOrYes {
	static List<Integer>[] graph;
	static Set<Integer> fanIdx;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		graph = new List[n + 1];
		for (int i = 0; i < n + 1; i ++) {
			graph[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			graph[from].add(to);
		}
		int fanCnt = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		fanIdx = new HashSet<>();
		for (int i = 0; i < fanCnt; i++) {
			fanIdx.add(Integer.parseInt(st.nextToken()));
		}
		if (!fanIdx.contains(1)) {
			dfs(1);
		}
		System.out.println("Yes");
	}

	private static void dfs(int start) {
		List<Integer> cur = graph[start];
		for (int i = 0; i < cur.size(); i++) {
			if (!fanIdx.contains(cur.get(i))) {
				dfs(cur.get(i));
			}
		}
		if (cur.isEmpty()) {
			System.out.println("yes");
			System.exit(0);
		}
	}
}
