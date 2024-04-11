import java.io.*;
import java.util.*;

public class HoseokTheCaptainOfAlley20183 {
	static class Node {
		int to;
		int w;
		int s;
		public Node(int to, int w, int s) {
			this.to = to;
			this.w = w;
			this.s = s;
		}
	}
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		long cost = Long.parseLong(st.nextToken());
		
		List<List<Node>> graph = new ArrayList<>();
		for (int i = 0 ; i < n + 1; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());

			graph.get(from).add(new Node(to, w, 0));
			graph.get(to).add(new Node(from, w, 0));
		}

		int[][] dist = new int[n + 1][2];
		for (int i = 0; i < n + 1; i++) {
			dist[i][0] = Integer.MAX_VALUE;
			dist[i][1] = Integer.MAX_VALUE;
		}
		dist[start][0] = 0;

		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.w - o2.w);
		pq.add(new Node(start, 0, 0));
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			
			if (dist[cur.to][1] < cur.s) continue;
			
			for (int i = 0; i < graph.get(cur.to).size(); i++) {
				Node adj = graph.get(cur.to).get(i);
				if (dist[adj.to][1] > Math.max(cur.s, adj.w) && cur.w + adj.w <= cost) {
					dist[adj.to][1] = Math.max(cur.s, adj.w);
					dist[adj.to][0] = cur.w + adj.w;
					pq.add(new Node(adj.to, dist[adj.to][0], dist[adj.to][1]));
				}
			}
		}
		long ans = dist[end][1] == Integer.MAX_VALUE ? -1 : dist[end][1];
		System.out.println(ans);
	}
}
