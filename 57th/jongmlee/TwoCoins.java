import java.io.*;
import java.util.*;

public class TwoCoins {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int cx1 = 0; int cy1 = 0;
		int cx2 = 0; int cy2 = 0;
		int cnt = 0;
		char[][] map = new char[n][m];
		for (int i = 0; i < n; i++) {
			String tmp = br.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = tmp.charAt(j);
				if (map[i][j] == 'o') {
					if (cnt == 0) {
						cx1 = i;
						cy1 = j;
						cnt++;
					} else {
						cx2 = i;
						cy2 = j;
					}
					map[i][j] = '.';
				}
			}
		}
		Queue<int[]> q = new LinkedList<>();
		boolean[][][][] v = new boolean[n][m][n][m];
		v[cx1][cy1][cx2][cy2] = true;
		q.add(new int[]{cx1, cy1, cx2, cy2, 0});
		int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			if (cur[4] >= 10) {
				System.out.println(-1);
				System.exit(0);
			}
			for (int i = 0; i < dir.length; i++) {
				int nx1 = cur[0] + dir[i][0];
				int ny1 = cur[1] + dir[i][1];
				int nx2 = cur[2] + dir[i][0];
				int ny2 = cur[3] + dir[i][1];
				// 동전 두 개 다 떨어지는 경우
				if ((nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= m)
					&& (nx2 < 0 || ny2 < 0|| nx2 >= n || ny2 >= m)) {
					continue;
				}
				// 하나만 떨어지는 경우
				if (nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= m
					|| nx2 < 0 || ny2 < 0|| nx2 >= n || ny2 >= m) {
					System.out.println(cur[4] + 1);
					System.exit(0);
				}
				if (map[nx1][ny1] == '#') {
					nx1 = cur[0];
					ny1 = cur[1];
				}
				if (map[nx2][ny2] == '#') {
					nx2 = cur[2];
					ny2 = cur[3];
				}
				if (nx1 == cur[0] && ny1 == cur[1] && nx2 == cur[2] && ny2 == cur[3]) {
					continue;
				}
				if (!v[nx1][ny1][nx2][ny2]) {
					v[nx1][ny1][nx2][ny2] = true;
					q.add(new int[]{nx1, ny1, nx2, ny2, cur[4] + 1});
				}
			}
		}
		System.out.println(-1);
	}
}
