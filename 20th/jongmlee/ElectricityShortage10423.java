import java.io.*;
import java.util.*;

public class ElectricityShortage1042 {
	static int[] parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		parents = new int[n + 1];
		for (int i = 0; i < parents.length; i++) {
			parents[i] = i;
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < k; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			parents[tmp] = -1;
		}
		List<int[]> list = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			list.add(new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
		}
		list.sort((x, y) -> x[2] - y[2]);
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int[] cur = list.get(i);
			if (find(cur[0]) != find(cur[1])) {
				union(cur[0], cur[1]);
				sum += cur[2];
			}
			if (isAllMatch()) {
				break;
			}
		}
		System.out.println(sum);
	}
	public static boolean isAllMatch() {
		for (int i = 1; i < parents.length; i++) {
			if (parents[i] != -1) {
				return false;
			}
		}
		return true;
	}
	public static int find(int a) {
		if (a == -1) {
			return -1;
		}
		if (a == parents[a]) {
			return a;
		}
		return parents[a] = find(parents[a]);
	}

	public static void union(int a, int b) {
		int aP = find(a);
		int bP = find(b);
		if (aP != bP) {
			if (aP == -1) {
				parents[bP] = -1;
			} else {
				parents[aP] = bP;
			}
		}
	}
}
