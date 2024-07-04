import java.io.*;
import java.util.*;

public class FriendCost {
	static int[] uf;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		uf = new int[n + 1];
		int[] costs = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			uf[i] = i;
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			costs[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			union(n1, n2);
		}
		for (int i = 1; i <= n; i++) {
			uf[i] = find(i);
		}
		HashMap<Integer, List<Integer>> map = new HashMap<>();
		for (int i = 1; i <= n; i++) {
			if (map.containsKey(uf[i])) {
				map.get(uf[i]).add(i);
			} else {
				map.put(uf[i], new ArrayList<>());
			}
		}
		int answer = 0;
		for (Integer key : map.keySet()) {
			int min = costs[key];
			for (int x : map.get(key)) {
				min = Math.min(costs[x], min);
			}
			answer += min;
		}
		if (answer <= k) {
			System.out.println(answer);
		} else {
			System.out.println("Oh no");
		}
	}
	static void union(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		if (fx < fy) {
			uf[fy] = fx;
		} else {
			uf[fx] = fy;
		}
	}
	static int find(int v) {
		if (v == uf[v]) {
			return v;
		}
		else {
			return uf[v] = find(uf[v]);
		}
	}
}
