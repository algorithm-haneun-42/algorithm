import java.io.*;
import java.util.*;

public class Alphabet {
	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	static int max = 0;
	static int r, c;
	static boolean[] v = new boolean[26];
	static int[][] board;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		board = new int[r][c];
		for (int i = 0; i < r; i++) {
			String tmp = br.readLine();
			for (int j = 0; j < c; j++) {
				board[i][j] = tmp.charAt(j) - 'A';
			}
		}
		dfs(0, 0, 1);
		System.out.println(max);
	}
	public static void dfs(int x, int y, int w) {
		v[board[x][y]] = true;
		max = Math.max(w, max);
		for (int i = 0; i < dir.length; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < r && ny < c && !v[board[nx][ny]]) {
				dfs(nx, ny, w + 1);
				v[board[nx][ny]] = false;
			}
		}
	}
}
