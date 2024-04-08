import java.io.*;
import java.util.*;

public class Exercise1956 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		int[][] dist = new int[v + 1][v + 1];
		for (int i = 1; i < v + 1; i++) {
			for (int j = 1; j < v + 1; j++) {
				dist[i][j] = Integer.MAX_VALUE;
			}
		}
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			dist[from][to] = w;
		}
		for (int k = 1; k < v + 1; k++) {
			for (int i = 1; i < v + 1; i++) {
				for (int j = 1; j < v + 1; j++) {
					if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
						dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
		System.out.println(findCycle(dist, v));
	}
	public static long findCycle(int[][] dist, int v) {
		long ret = Integer.MAX_VALUE;
		for (int i = 1; i < v + 1; i++) {
			if (dist[i][i] != Integer.MAX_VALUE) {
				ret = Math.min(dist[i][i], ret);
			}
		}
		if (ret != Integer.MAX_VALUE) return ret;
		return -1;
	}
}
