import java.io.*;
import java.util.*;

public class CreateShape {
	static int[][] board;
	static List<Integer> amounts;
	static int[][] dir = {{0, 1}, {1, 0}, {-1 ,0}, {0, -1}};
	static int max = 0;
	static int num = 2;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		board = new int[n][m];
		amounts = new ArrayList<>();
		amounts.add(0);
		amounts.add(0);
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
					bfs(i, j);
					num++;
				}
			}
		}
		Set<Integer> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) {
					for (int k = 0; k < dir.length; k++) {
						int nx = i + dir[k][0];
						int ny = j + dir[k][1];
						if (nx >= 0 && ny >= 0 && nx < board.length && ny < board[0].length && board[nx][ny] != 0) {
							set.add(board[nx][ny]);
						}
					}
					int sum = 0;
					for (int x : set) {
						sum += amounts.get(x);
					}
					sum++;
					max = Math.max(sum, max);
					set.clear();
				}
			}
		}
		System.out.println(max);
	}
	public static void bfs(int x, int y) {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{x, y});
		board[x][y] = num;
		int cnt = 1;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			for (int i = 0; i < dir.length; i++) {
				int nx = cur[0] + dir[i][0];
				int ny = cur[1] + dir[i][1];
				if (nx >= 0 && ny >= 0 && nx < board.length && ny < board[0].length && board[nx][ny] == 1) {
					board[nx][ny] = num;
					cnt++;
					q.add(new int[]{nx, ny});
				}
			}
		}
		amounts.add(cnt);
	}
}
