import java.io.*;
import java.util.*;

public class SecretGroup {
	static final int INF = 10000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int[][] graph = new int[n + 1][n + 1];
			for (int i = 1; i <= n; i++) {
				Arrays.fill(graph[i], INF);
				graph[i][i] = 0;
			}
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				graph[a][b] = c;
				graph[b][a] = c;
			}
			int k = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			int[] fr = new int[k];
			for (int i = 0; i < k ;i++) {
				fr[i] = Integer.parseInt(st.nextToken());
			}
			for (int s = 1; s <= n; s++) {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						if (graph[i][s] != INF && graph[s][j] != INF) {
							graph[i][j] = Math.min(graph[i][s] + graph[s][j], graph[i][j]);
						}
					}
				}
			}
			int min = Integer.MAX_VALUE;
			List<Integer> minList = new ArrayList<>();
			for (int j = 1; j <= n; j++) {
				int sum = 0;
				for (int i = 0; i < fr.length; i++) {
					sum += graph[fr[i]][j];
				}
				if (sum < min) {
					min = sum;
					minList.clear();
					minList.add(j);
				} else if (sum == min) {
					minList.add(j);
				}
			}
			
			System.out.println(minList.stream().min(Comparator.naturalOrder()).get());
		}
	}
}
