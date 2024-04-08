import java.io.*;
import java.util.*;

public class SeokangGround14938 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); // 정점의 개수
		int m = Integer.parseInt(st.nextToken()); // 수색범위
		int r = Integer.parseInt(st.nextToken()); // 간선의 개수
		int[] itemCnt = new int[n + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < n + 1; i++) {
			itemCnt[i] = Integer.parseInt(st.nextToken());
		}
		int[][] dist = new int[n + 1][n + 1];
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (i != j) {
					dist[i][j] = Integer.MAX_VALUE;
				}
			}
		}
		for (int i = 0 ; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			dist[from][to] = w;
			dist[to][from] = w;
		}
		for (int k = 1; k < n + 1; k++) {
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
						dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
		long result = 0;
		long tmp;
		for (int i = 1; i < n + 1; i++) {
			tmp = 0;
			for (int j = 1; j < n + 1; j++) {
				if (dist[i][j] <= m) {
					tmp += itemCnt[j];
				}
			}
			result = Math.max(tmp, result);
		}
		System.out.println(result);
	}
}
