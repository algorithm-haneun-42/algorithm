import java.io.*;
import java.util.*;

public class DetectingMarble {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] dist = new int[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int to = Integer.parseInt(st.nextToken());
			int from = Integer.parseInt(st.nextToken());
			dist[from][to]++;
		}
		for (int k = 1; k < n + 1; k++) {
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					if (dist[i][k] > 0 && dist[k][j] > 0) {
						dist[i][j] = Math.max(dist[i][k] + dist[k][j], dist[i][j]);
					}
				}
			}
		}
		//System.out.println(Arrays.deepToString(dist));
		int answer = 0;
		for (int i = 1; i < n + 1; i++) {
			int cnt = 0;
			for (int j = 1; j < n + 1; j++) {
				if (dist[i][j] > 0) cnt++;
			}
			if (cnt > n / 2) answer++;
		}
		for (int i = 1; i < n + 1; i++) {
			int cnt = 0;
			for (int j = 1; j < n + 1; j++) {
				if (dist[j][i] > 0) cnt++;
			}
			if (cnt > n / 2) answer++;
		}
		System.out.println(answer);
	}
}
