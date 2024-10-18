import java.io.*;
import java.util.*;

public class ExpressionOfUnion {
	static int[] parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		parents = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			parents[i] = i;
		}
		while (m-- > 0) {
			st = new StringTokenizer(br.readLine());
			int op = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (op == 0) {
				union(a, b);
			} else {
				if (find(a) == find(b)) {
					System.out.println("YES");
				} else {
					System.out.println("NO");
				}
			}
		}
	}
	static void union(int a, int b) {
		int ra = find(a);
		int rb = find(b);
		
		if (ra < rb) {
			parents[rb] = parents[ra];
		} else {
			parents[ra] = parents[rb];
		}
	}
	
	static int find(int a) {
		if (parents[a] == a) {
			return a;
		}
		return parents[a] = find(parents[a]);
	}
}
