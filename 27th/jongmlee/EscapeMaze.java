import java.util.*;

class EscapeMaze {
	static char[][] board;
	static Point s, l;
	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	public int solution(String[] maps) {
		board = new char[maps.length][maps[0].length()];
		for (int i = 0; i < maps.length; i++) {
			String tmp = maps[i];
			for (int j = 0; j < maps[0].length(); j++) {
				board[i][j] = tmp.charAt(j);
				if (board[i][j] == 'S') {
					s = new Point(i, j, 0);
				} else if (board[i][j] == 'L') {
					l = new Point(i, j, 0);
				}
			}
		}
		int lw = dfs('L');
		int le = dfs('E');
		if (lw == -1 || le == -1) return -1;
		return lw + le;
	}
	public static int dfs(char c) {
		Queue<Point> q = new LinkedList<>();
		boolean[][] v = new boolean[board.length][board[0].length];
		if (c == 'L') {
			q.add(s);
			v[s.x][s.y] = true;
		}
		else if (c == 'E') {
			q.add(l);
			v[l.x][l.y] = true;
		}
		while (!q.isEmpty()) {
			Point cur = q.poll();
			if (board[cur.x][cur.y] == c) {
				return cur.w;
			}
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx < 0 || nx >= board.length || ny <0 || ny >= board[0].length || board[nx][ny] == 'X' || v[nx][ny]) continue;
				v[nx][ny] = true;
				q.add(new Point(nx, ny, cur.w + 1));
			}
		}
		return -1;
	}
	static class Point {
		int x;
		int y;
		int w;
		public Point(int x, int y, int w) {
			this.x = x;
			this.y = y;
			this.w = w;
		}
	}
}