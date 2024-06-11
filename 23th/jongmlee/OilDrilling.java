import java.io.*;
import java.util.*;

class OilDrilling {
	static int[][] map;
	static int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	static int[] cnts = new int[100000];
	static int n, m;
	public int solution(int[][] land) {
		int answer = 0;
		map = land;
		n = land.length;
		m = land[0].length;
		int sum;
		int idx = 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					map[i][j] = idx;
					bfs(i, j, idx);
					idx++;
				}
			}
		}
		HashSet<Integer> set = new HashSet<>();
		for (int i = 0; i < m; i++) {
			set.clear();
			sum = 0;
			for (int j = 0; j < n; j++) {
				if (map[j][i] != 0 && !set.contains(map[j][i])) {
					sum += cnts[map[j][i]];
					set.add(map[j][i]);
				}
			}
			answer = Math.max(answer, sum);
		}
		return answer;
	}
	static void bfs(int x, int y, int idx) {
		int ret = 0;
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{x, y});
		while (!q.isEmpty()) {
			ret += 1;
			int[] cur = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = dir[i][0] + cur[0];
				int ny = dir[i][1] + cur[1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != 1) {
					continue;
				}
				map[nx][ny] = idx;
				q.add(new int[]{nx, ny});
			}
		}
		cnts[idx] = ret;
	}
}