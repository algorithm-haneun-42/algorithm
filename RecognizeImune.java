import java.io.*;
import java.util.*;

public class RecognizeImune {
	static int n, m;
	static int[][] origin, after;
	static boolean[][] originVisit;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		origin = new int[n][m];
		after = new int[n][m];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				origin[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				after[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		originVisit = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!originVisit[i][j]) {
					bfs(i, j);
				}
			}
		}
		System.out.println("NO");
	}

	static void bfs(int x, int y) {
		int[][] dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		boolean[][] v = new boolean[n][m];
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{x, y});
		v[x][y] = true;
		originVisit[x][y] = true;
		int first = origin[x][y];
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			for (int i = 0; i < dir.length; i++) {
				int nx = dir[i][0] + cur[0];
				int ny = dir[i][1] + cur[1];
				if (nx < 0 || ny < 0|| nx >= n || ny >= m || origin[nx][ny] != first || v[nx][ny]) continue;
				v[nx][ny] = true;
				originVisit[nx][ny] = true;
				q.add(new int[]{nx, ny});
			}
		}
		
		for (int i = 1; i <= 1000; i++) {
			fill(i, v);
			if (Arrays.deepEquals(origin, after)) {
				System.out.println("YES");
				System.exit(0);
			}
		}
		fill(first, v);
	}
	static void fill(int x, boolean[][] v) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j]) origin[i][j] = x;
			}
		}
	}
}
