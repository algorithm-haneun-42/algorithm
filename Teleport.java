import java.io.*;
import java.sql.Array;
import java.util.*;

public class Teleport {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		List<int[]> list = new ArrayList<>();
		for (int i  =0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			list.add(new int[]{s, x, y});
		}
		int[][] dist = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)  {
					dist[i + 1][j + 1] = 0;
					continue;
				}
				int nomalDist = Math.abs(list.get(i)[1] - list.get(j)[1])
						+ Math.abs(list.get(i)[2] - list.get(j)[2]);
				if (list.get(i)[0] == 1 && list.get(j)[0] == 1) {
					dist[i + 1][j + 1] = Math.min(t, nomalDist);
				} else {
					dist[i + 1][j + 1] = nomalDist;
				}
			}
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int m = Integer.parseInt(br.readLine());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			System.out.println(dist[a][b]);
		}
	}
}
