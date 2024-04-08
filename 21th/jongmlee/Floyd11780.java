import java.io.*;
import java.util.*;

public class Floyd11780 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		int[][] dist = new int[n + 1][n + 1];
		int[][] next = new int[n + 1][n + 1];
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (i != j) {
					dist[i][j] = Integer.MAX_VALUE;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			dist[from][to] = Math.min(dist[from][to], w);
			next[from][to] = to;
		}
		for (int k = 1; k < n + 1; k++) {
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
						if (dist[i][j] > dist[i][k] + dist[k][j]) {
							dist[i][j] = dist[i][k] + dist[k][j];
							next[i][j] = next[i][k];
						}
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (dist[i][j] == Integer.MAX_VALUE) dist[i][j] = 0;
				sb.append(dist[i][j]).append(' ');
			}
			sb.append('\n');
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (dist[i][j] == 0 || dist[i][j] == Integer.MAX_VALUE) {
					sb.append(0).append('\n');
					continue;
				}
				List<Integer> list = new ArrayList<>();
				int start = i;
				while (start != j) {
					list.add(start);
					start = next[start][j];
				}
				list.add(j);
				sb.append(list.size()).append(' ');
				list.forEach(x -> sb.append(x).append(' '));
				sb.append('\n');
			}
		}
		System.out.println(sb);
	}
}
