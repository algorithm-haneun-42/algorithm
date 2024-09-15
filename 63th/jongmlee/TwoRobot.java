import java.io.*;
import java.util.*;

public class TwoRobot {
	static List<List<Node>> graph;
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
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		if (n == 1 || a == b) {
			System.out.println(0);
			return;
		}
		graph = new ArrayList<>();
		for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int to = Integer.parseInt(st.nextToken());
			int from = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.get(to).add(new Node(from, w));
			graph.get(from).add(new Node(to, w));
		}
		int[] distA = new int[n + 1];
		int[] distB = new int[n + 1];
		dajikstra(a, distA);
		dajikstra(b, distB);
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < graph.size(); i++) {
			List<Node> cur = graph.get(i);
			for (Node x : cur) {
				min = Math.min(min, distA[i] + distB[x.to]);
			}
		}
		System.out.println(min);
	}
	static void dajikstra(int start, int[] dist) {
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start] = 0;
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.w - o2.w);
		pq.add(new Node(start, 0));
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			if (dist[cur.to] < cur.w) continue;
			for (int i = 0; i < graph.get(cur.to).size(); i++) {
				Node adj = graph.get(cur.to).get(i);
				if (dist[adj.to] > dist[cur.to] + adj.w) {
					dist[adj.to] = dist[cur.to] + adj.w;
					pq.add(new Node(adj.to, dist[adj.to]));
				}
			}
		}
	}
}
