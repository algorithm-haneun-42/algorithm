import java.io.*;
import java.util.*;

public class TwoDots {
	static int n, m, sx, sy;
	static char[][] map;
	static boolean[][] v, v1;
	static int dir[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new char[n][m];
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < m; j++) {
				map[i][j] = line.charAt(j);
			}
		}
		v = new boolean[n][m];
		v1 = new boolean[n][m];
		boolean flag = false;
		loop:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!v1[i][j]) {
					sx = i;
					sy = j;
					if (dfs(i, j, 0)) {
						flag = true;
						System.out.println("Yes");
						break loop;
					};
					v1[i][j] = true;
				}
			}
		}
		if (!flag) {
			System.out.println("No");
		}
	}
	static boolean dfs(int x, int y, int depth) {
		for (int i = 0; i < dir.length; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (depth > 1 && nx == sx && ny == sy) {
				return true;
			}
			if (!v[nx][ny] && map[nx][ny] == map[x][y]) {
				v[x][y] = true;
				return dfs(nx, ny, depth + 1);
			}
		}
		return false;
	}
}
