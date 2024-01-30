import java.io.*;
import java.util.*;

public class Cabage1012 {
	static class Point {
		int x;
		int y;
		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		Queue<Point> q = new LinkedList<>();
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());

			int[][] farm = new int[m][n];
			for (int i = 0; i < k; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				farm[x][y] = 1;
			}

			q.clear();
			int answer = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (farm[i][j] == 1) {
						farm[i][j] = 0;
						q.add(new Point(i, j));
						answer++;
						bfs(q, farm, m, n);
					}
				}
			}
			System.out.println(answer);
		}
	}
	private static void bfs(Queue<Point> q, int[][] farm, int m, int n) {
		int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		while(!q.isEmpty()) {
			Point cur = q.poll();
			for (int i = 0; i< 4; i++) {
				int newX = cur.x + dir[i][0];
				int newY = cur.y + dir[i][1];

				if (newX < 0 || newX >= m || newY < 0 || newY >= n)
					continue;
				if (farm[newX][newY] == 0)
					continue;
				farm[newX][newY] = 0;
				q.add(new Point(newX, newY));
			}
		}
	}
}
