import java.io.*;
import java.util.*;

public class DistanceBetweenNodes {
	static class Node {
		int to;
		int c;
		public Node(int to, int c) {
			this.to = to;
			this.c = c;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		List<List<Node>> graph = new ArrayList<>();
		for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			graph.get(from).add(new Node(to, c));
			graph.get(to).add(new Node(from, c));
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			Queue<Node> q = new LinkedList<>();
			boolean[] v = new boolean[n + 1];
			v[x] = true;
			q.add(new Node(x, 0));
			while (!q.isEmpty()) {
				Node cur = q.poll();
				if (cur.to == y) {
					System.out.println(cur.c);
					break;
				}
				for (int j = 0; j < graph.get(cur.to).size(); j++) {
					Node next = graph.get(cur.to).get(j);
					if (!v[next.to]) {
						v[next.to] = true;
						q.add(new Node(next.to, cur.c + next.c));
					}
				}
			}
		}
	}
}
