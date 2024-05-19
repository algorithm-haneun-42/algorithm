import java.util.*;

class ModifyNumber {
	static int[] dir;
	static boolean[] v;
	public int solution(int x, int y, int n) {
		dir = new int[]{n, 2, 3};
		v = new boolean[y + 1];
		int answer = bfs(x, y, n);
		return answer;
	}
	static int bfs(int x, int y, int n) {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{x, 0});
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			if (cur[0] == y) {
				return cur[1];
			}
			for (int i = 0 ; i < 3; i++) {
				int nx;
				if (i == 0) {
					nx = cur[0] + dir[i];
				} else {
					nx = cur[0] * dir[i];
				}
				if (nx <= y && !v[nx]) {
					v[nx] = true;
					q.add(new int[]{nx, cur[1] + 1});
				}
			}
		}
		return -1;
	}
}
