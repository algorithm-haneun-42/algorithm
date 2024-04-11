import java.io.*;
import java.util.*;

public class Party1238 {
	static int n;
	static List<List<Node>> graph = new ArrayList<>();

	static class Node {
		int to;
		int w;
		public Node(int to, int w) {
			this.to = to;
			this.w = w;
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
		
		for (int i = 0; i < m + 1; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 1; i < m + 1; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			graph.get(from).add(new Node(to, w));
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i != x) {
				ans = Math.max(dijkstra(i, x) + dijkstra(x, i), ans);
			}
		}
		System.out.println(ans);
	}
	
	public static int dijkstra(int start, int end) {
		int[] dist = new int[n + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start] = 0;
		
		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> (o1.w - o2.w));
		pq.add(new Node(start, 0));
		
		while (!pq.isEmpty()) {
			Node cur = pq.poll();

			if (dist[cur.to] < cur.w) continue;

			for (int i = 0; i < graph.get(cur.to).size(); i++) {
				Node adj = graph.get(cur.to).get(i);
				
				if (dist[adj.to] > adj.w + cur.w) {
					dist[adj.to] = adj.w + cur.w;
					pq.add(new Node(adj.to, dist[adj.to]));
				}
			}
		}
		return dist[end];
	}
}
