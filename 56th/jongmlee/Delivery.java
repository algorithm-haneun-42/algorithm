import java.io.*;
import java.util.*;

public class Delivery {
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
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		List<List<Node>> graph = new ArrayList<>();
		for (int i = 0; i < n + 1; i++) graph.add(new ArrayList<>());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.get(from).add(new Node(to, w));
			graph.get(to).add(new Node(from, w));
		}
		int[] dist = new int[n + 1];
		Arrays.fill(dist, 50000001);
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.w - o2.w);
		pq.add(new Node(1, 0));
		dist[1] = 0;
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			if (dist[cur.to] < cur.w) continue;
			for (int i = 0; i < graph.get(cur.to).size(); i++) {
				Node adj = graph.get(cur.to).get(i);
				if (dist[adj.to] > dist[cur.to] + adj.w) {
					dist[adj.to] = dist[cur.to] + adj.w;
					pq.offer(new Node(adj.to, dist[adj.to]));
				}
			}
		}
		System.out.println(dist[n]);
	}
}
