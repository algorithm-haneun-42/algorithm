import java.io.*;
import java.util.*;

public class LackOfElecetricity {
	static int[] parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		parents = new int[n + 1];
		for (int i = 0; i < n + 1; i++) parents[i] = i;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < k; i++) {
			parents[Integer.parseInt(st.nextToken())] = -1;
		}
		List<int[]> list = new ArrayList<>();
		for (int i = 0; i < m; i++)                                                                                                                                                                                                                                                                                                                                                                                      {
			st = new StringTokenizer(br.readLine());
			int from  = Integer.parseInt(st.nextToken());
			int to  = Integer.parseInt(st.nextToken());
			int w  = Integer.parseInt(st.nextToken());
			list.add(new int[]{from, to, w});
		}
		list.sort((x, y) -> x[2] - y[2]); // 오름차순 정렬
		int sum = 0;
		for (int i = 0; i < m; i++) {
			int[] cur = list.get(i);
			if (find(cur[0]) != find(cur[1])) {
				union(cur[0], cur[1]);
				sum += cur[2];
			}
			if (check()) {
				break;
			}
		}
		System.out.println(sum);
	}
	static boolean check() {
		for (int i = 1; i < parents.length; i++) {
			if (parents[i] != -1) {
				return false;
			}
		}
		return true;
	}
	static int find(int a) {
		if (a == -1) {
			return -1;
		}
		if (a == parents[a]) {
			return a;
		}
		return parents[a] = find(parents[a]);
	}
	static void union(int a, int b) {
		int na = find(a);
		int nb = find(b);
		if (na != nb) {
			if (na == -1) {
				parents[nb] = -1;
			} else {
				parents[na] = nb;
			}
		}
	}
}
