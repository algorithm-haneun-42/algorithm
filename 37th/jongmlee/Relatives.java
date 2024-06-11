import java.io.*;
import java.util.*;

public class Relatives {
	static class Node {
		int idx;
		int w;
		public Node(int idx, int w) {
			this.idx = idx;
			this.w = w;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int o1 = Integer.parseInt(st.nextToken());
		int o2 = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(br.readLine());
		List<List<Integer>> graph = new ArrayList<>();
		for (int i = 0; i < n + 1; i++) {
			graph.add(new ArrayList<Integer>());
		}	
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			graph.get(n1).add(n2);
			graph.get(n2).add(n1);
		}
		Queue<Node> q = new LinkedList<>();
		boolean[] v = new boolean[n + 1];
		v[o1] = true;
		q.add(new Node(o1, 0));
		while (!q.isEmpty()) {
			Node cur = q.poll();
			if (cur.idx == o2) {
				System.out.println(cur.w);
				return;
			}
			for (int i = 0; i < graph.get(cur.idx).size(); i++) {
				int adj = graph.get(cur.idx).get(i);
				if (!v[adj]) {
					v[adj] = true;
					q.add(new Node(adj, cur.w + 1));
				}
			}
		}
		System.out.println(-1);
	}
}
