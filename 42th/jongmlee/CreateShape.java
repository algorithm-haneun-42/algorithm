import java.io.*;
import java.util.*;

public class CreateShape {
	static int[][] board;
	static int[][] dir = {{0, 1}, {1, 0}, {-1 ,0}, {0, -1}};
	static int max = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		board = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		bfs();
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//			board[i][j] = 1;
		//			bfs();
		//			board[i][j] = 0;
		//		}
		//	}
		//}
		System.out.println(max);
	}
	public static void bfs() {
		boolean[][] v = new boolean[board.length][board[0].length];
		Queue<int[]> q = new LinkedList<>();
		int cnt = 0;
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == 1 && !v[i][j]) {
					v[i][j] = true;
					q.add(new int[]{i, j, 1});
					while (!q.isEmpty()) {
						int[] cur = q.poll();
						for (int k = 0; k < dir.length; k++) {
							int nx = cur[0] + dir[k][0];
							int ny = cur[1] + dir[k][1];
							if (nx >= 0 && ny >= 0 && nx < board.length && ny < board[0].length && board[nx][ny] == 1 && !v[nx][ny]) {
								v[nx][ny] = true;
								cnt++;
								q.add(new int[]{nx, ny});
							}
						}
					}
					max = Math.max(cnt, max);
				}
			}
		}
	}
}
