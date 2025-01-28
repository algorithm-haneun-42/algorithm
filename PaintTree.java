import java.io.*;
import java.util.*;

public class PaintTree {
	static int[] cur, target;
	static boolean[] v;
	static List<List<Integer>> tree;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		target = new int[n + 1];
		cur = new int[n + 1];
		v = new boolean[n + 1];
		tree = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			target[i] = Integer.parseInt(st.nextToken());
			tree.add(new ArrayList<>());
		}
		tree.add(new ArrayList<>());

		for (int i = 1; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		answer = target[1] == 0 ? 0 : 1;
		v[1] = true;
		dfs(1);
		System.out.println(answer);
	}

	private static void dfs(int num) {
		for (int i  =0; i < tree.get(num).size(); i++) {
			int node = tree.get(num).get(i);
			if (!v[node]) {
				v[node] = true;
				if (target[num] != target[node]) {
					answer++;
				}
				dfs(node);
			}
		}
	}
}
