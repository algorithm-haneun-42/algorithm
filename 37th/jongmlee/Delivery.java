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
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		List<List<Node>> graph = new ArrayList<>();
		for (int i = 0; i < v + 1; i++) {
			graph.add(new ArrayList<>());
		}
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.get(from).add(new Node(to, w));
			graph.get(to).add(new Node(from, w));
		}
		int[] dist = new int[v + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(1, 0));
		dist[1] = 0;
		while (!pq.isEmpty()) {
			Node cur = pq.poll();
			if(dist[cur.to] < cur.w) continue;
			for(int i = 0; i < graph.get(cur.to).size();i++) {
				int cost = dist[cur.to] + graph.get(cur.to).get(i).w;
				if( cost < dist[graph.get(cur.to).get(i).to]) {
					dist[graph.get(cur.to).get(i).to] = cost;
					pq.offer(new Node( graph.get(cur.to).get(i).to, cost));
				}
			}
		}
		System.out.println(dist[v]);
	}
}
