import java.util.*;
import java.io.*;

class GetMinimum1916 {
	static class Node {
		int to;
		int w;
		public Node(int to, int w) {
			this.to = to;
			this.w = w;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		
		List<List<Node>> graph = new ArrayList<>();
		for (int i = 0; i < n + 1; i++) {
			graph.add(new ArrayList<>());
		}
		for (int i = 1; i <= m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());

			graph.get(from).add(new Node(to, w));
		}
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());

		int[] dist = new int[n + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start] = 0;

		PriorityQueue<Node> pq = new PriorityQueue<>((x, y) -> x.w - y.w);
		pq.add(new Node(start, 0));

		while (!pq.isEmpty()) {
			Node cur = pq.poll();

			if (dist[cur.to] < cur.w) {
				continue;
			}
			
			for (int i = 0; i < graph.get(cur.to).size(); i++) {
				Node adj = graph.get(cur.to).get(i);

				if (dist[adj.to] > cur.w + adj.w) {
					dist[adj.to] = cur.w + adj.w;
					pq.add(new Node(adj.to, dist[adj.to]));
				}
			}
		}
		System.out.println(dist[end]);
	}
}