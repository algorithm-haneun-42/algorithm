import java.io.*;
import java.util.*;

public class MooTube {
	static int n;
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
		n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		graph = new ArrayList<>();
		for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
		for (int i = 0 ; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph.get(x).add(new Node(y, w));
			graph.get(y).add(new Node(x, w));
		}
		for (int i = 0; i < q; i++) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int idx = Integer.parseInt(st.nextToken());
			find(k, idx);
		}
	}
	static void find(int k, int idx) {
		Queue<Node> q = new LinkedList<>();
		boolean[] check = new boolean[n + 1];
		q.add(new Node(idx, Integer.MAX_VALUE));
		check[idx] = true;
		int cnt = 0, linkMinCost = 0;
		while(!q.isEmpty()) {
			Node cur = q.poll();
			List<Node> link = graph.get(cur.to);
			for(int i = 0; i < link.size(); i++) {
				if (check[link.get(i).to]) continue;
				linkMinCost = Math.min(link.get(i).w, cur.w);
				if (linkMinCost >= k) {
					check[link.get(i).to] = true;
					cnt++;
					q.add(new Node(link.get(i).to,linkMinCost));
				}
			}
		}
		System.out.println(cnt);
	}
}
