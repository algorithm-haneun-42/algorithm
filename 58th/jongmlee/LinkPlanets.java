import java.io.*;
import java.util.*;

public class LinkPlanets {
	static int[] parents;
	static class Node {
		int x; int y; int d;
		public Node(int x, int y, int d) {
			this.x = x;
			this.y = y;
			this.d = d;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		int[][] edges = new int[n + 1][n + 1];
		List<Node> nodes = new ArrayList<>();
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= n; j++) {
				edges[i][j] = Integer.parseInt(st.nextToken());
				if (j > i) {
					nodes.add(new Node(i, j, edges[i][j]));
				}
			}
		}
		nodes.sort((o1, o2) -> o1.d - o2.d);
		long sum = 0;
		parents = new int[n + 1];
		for (int i = 0; i < parents.length; i++) parents[i] = i;
		for (Node cur : nodes) {
			if (find(cur.x) != find(cur.y)) {
				union(cur.x, cur.y);
				sum += cur.d;
			}
		}
		System.out.println(sum);
	}
	static int find(int x) {
		if (x == parents[x]) {
			return x;
		}
		return parents[x] = find(parents[x]);
	}
	static void union(int x, int y) {
		int xr = find(x);
		int yr = find(y);
		if (xr != yr) {
			parents[yr] = xr;
		}
	}
}
