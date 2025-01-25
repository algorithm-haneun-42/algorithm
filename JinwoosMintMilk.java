import java.io.*;
import java.util.*;

public class JinwoosMintMilk {
	static int n, mintHp, max;
	static int[][] map;
	static List<int[]> mintPointList;
	static int[] startPoint;
	static boolean[][] v;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int curHp = Integer.parseInt(st.nextToken());
		mintHp = Integer.parseInt(st.nextToken());

		map = new int[n][n];
		mintPointList = new ArrayList<>();
		startPoint = new int[2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1) {
					startPoint[0] = i;
					startPoint[1] = j;
				}
				if (map[i][j] == 2) {
					mintPointList.add(new int[]{i, j});
				}
			}
		}
		v = new boolean[n][n];
		dfs(startPoint[0], startPoint[1], curHp, 0);
		System.out.println(max);
	}

	private static void dfs(int x, int y, int curHp, int cnt) {
		if (getDistance(x, y, startPoint[0], startPoint[1]) <= curHp) {
			max = Math.max(max, cnt);
		}
		for (int[] cur : mintPointList) {
			int dist = getDistance(x, y, cur[0], cur[1]);
			if (!v[cur[0]][cur[1]] && dist <= curHp) {
				v[cur[0]][cur[1]] = true;
				dfs(cur[0], cur[1], curHp - dist + mintHp, cnt + 1);
				v[cur[0]][cur[1]] = false;
			}
		}
	}

	private static int getDistance(int x1, int y1, int x2, int y2) {
		return Math.abs(x1 - x2) + Math.abs(y1 - y2);
	}
}
