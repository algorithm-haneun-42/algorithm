import java.io.*;
import java.util.*;

public class TimeMachine {
	static class Node {
		int from;
		int to;
		int w;
		public Node(int from, int to, int w) {
			this.from = from;
			this.to = to;
			this.w = w;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		if (v == 1) {System.out.println(0); return;}
		List<Node> graph = new ArrayList<>();
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.add(new Node(from, to, w));
		}
		long[] dist = new long[v + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[1] = 0;
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < e; j++) {
				Node cur = graph.get(j);
				if (dist[cur.from] != Integer.MAX_VALUE && dist[cur.to] > dist[cur.from] + cur.w) {
					dist[cur.to] = dist[cur.from] + cur.w;
				}
			}
		}
		loop:
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < e; j++) {
				Node cur = graph.get(j);
				if (dist[cur.from] != Integer.MAX_VALUE && dist[cur.to] > dist[cur.from] + cur.w) {
					dist[cur.to] = -1;
					break loop;
				}
			}
		}
		for (int i = 2; i < dist.length; i++) {
			if (dist[i] == -1 || dist[i] == Integer.MAX_VALUE) {
				System.out.println(-1);
			}
			System.out.println(dist[i]);
		}
	}
}
