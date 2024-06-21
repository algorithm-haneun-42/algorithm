import java.io.*;
import java.util.*;

public class Bacon {
	static final int MAX = 10000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] graph = new int[n][n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(graph[i], MAX);
			graph[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken()) - 1;
			int to = Integer.parseInt(st.nextToken()) - 1;
			graph[from][to] = 1;
			graph[to][from] = 1;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = Math.min(graph[i][k] + graph[k][j], graph[i][j]);
				}
			}
		}
		int answer = 0;
		int min = MAX;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (graph[i][j] != MAX) {
					sum += graph[i][j];
				}
			}
			if (sum < min) {
				min = sum;
				answer = i;
			}
		}
		System.out.println(answer + 1);
	}
}
