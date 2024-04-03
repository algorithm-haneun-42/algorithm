import java.io.*;
import java.util.*;

public class CitySplitPlan1647 {
	static int[] parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		parents = new int[n + 1];
		for (int i = 0; i < parents.length; i++) {
			parents[i] = i;
		}
		ArrayList<int[]> list = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			list.add(new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
		}
		list.sort((x, y) -> x[2] - y[2]);
		int sum = 0;
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < m; i++) {
			int[] cur = list.get(i);
			if (find(cur[0]) != find(cur[1])) {
				union(cur[0], cur[1]);
				sum += cur[2];
				if (max < cur[2]) {
					max = cur[2];
				}
			}
		}
		sum -= max;
		System.out.println(sum);
	}
	public static void union(int a, int b) {
		int aP = find(a);
		int bP = find(b);
		if (aP != bP) {
			parents[aP] = bP;
		}
	}
	public static int find(int a) {
		if (a == parents[a]) {
			return a;
		}
		return parents[a] = find(parents[a]);
	}
}
