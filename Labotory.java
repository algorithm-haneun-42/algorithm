import java.io.*;
import java.util.*;

public class Labotory {
	static int max = 0;
	static int[][] map;
	static int n, m;
	static int[][] dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n * m; i++) {
			if (map[i / m][i % m] != 0) continue;
			for (int j = i + 1; j < n * m; j++) {
				if (map[j / m][j % m] != 0) continue;
				for (int k = j + 1; k < n * m; k++) {
					if (map[k / m][k % m] != 0) continue;
					map[i / m][i % m] = map[j / m][j % m] = map[k / m][k % m] = 1;
					bfs();
					map[i / m][i % m] = map[j / m][j % m] = map[k / m][k % m] = 0;
				}
			}
		}
		System.out.println(max);
	}
	static void bfs() {
		Queue<int[]> q = new LinkedList<>();
		boolean[][] v = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 2) {
					q.add(new int[]{i, j});
				}
			}
		}
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			v[cur[0]][cur[1]] = true;
			for (int i = 0; i < dir.length; i++) {
				int nx = cur[0] + dir[i][0];
				int ny = cur[1] + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] || map[nx][ny] != 0) continue;
				q.add(new int[]{nx, ny});
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0 && !v[i][j]) {
					cnt++;
				}
			}
		}
		max = Math.max(cnt, max);
	}
}
