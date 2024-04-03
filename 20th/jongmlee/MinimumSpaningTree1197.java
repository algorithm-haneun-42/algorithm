import java.io.*;
import java.util.*;

public class MinimumSpaningTree1197 {
	
	static int[] parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		parents = new int[v + 1];
		for (int i = 0; i < parents.length; i++) {
			parents[i] = i;
		}
		List<Edge> edges = new ArrayList<>();
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			edges.add(new Edge(Integer.parseInt(st.nextToken()),
				Integer.parseInt(st.nextToken()),
				Integer.parseInt(st.nextToken())));
		}
		Collections.sort(edges);
		int sum = 0;
		for (int i = 0; i < e; i++) {
			Edge cur = edges.get(i);
			if (find(cur.from) != find(cur.to)) {
				union(cur.from, cur.to);
				sum += cur.w;
			}
		}
		System.out.println(sum);
	}
	public static void union(int a, int b) {
		int aP = find(a);
		int bP = find(b);

		if (aP != bP) {
			parents[aP] = bP;
		}
	}
	public static int find(int a) {
		if (a == parents[a]) {
			return a;
		}
		return parents[a] = find(parents[a]);
	}
	static class Edge implements Comparable<Edge>{
		int from;
		int to;
		int w;
		Edge(int from, int to, int w) {
			this.from = from;
			this.to = to;
			this.w = w;
		}
		@Override
		public int compareTo(Edge o) {
			return this.w - o.w;
		}
	}
}
