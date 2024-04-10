import java.io.*;
import java.util.*;

public class Algospot1261 {
	static class Node {
		int x;
		int y;
		int w;
		public Node(int x, int y, int w) {
			this.x = x;
			this.y = y;
			this.w = w;
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int[][] dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		
		int[][] graph = new int[n][m];
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < m; j++) {
				graph[i][j] = line.charAt(j) - '0';
			}
		}

		int[][] dist = new int[n][m];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dist[i], Integer.MAX_VALUE);
		}
		dist[0][0] = 0;

		boolean[][] v = new boolean[n][m];

		PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.w - o2.w);
		v[0][0] = true;
		pq.add(new Node(0, 0, 0));
		while (!pq.isEmpty()) {
			Node cur = pq.poll();

			if (dist[cur.x][cur.y] < cur.w) continue;
			
			for (int i = 0; i < dir.length; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (v[nx][ny]) continue;
				if (dist[nx][ny] > graph[nx][ny] + cur.w) {
					dist[nx][ny] = graph[nx][ny] + cur.w;
					pq.add(new Node(nx, ny, dist[nx][ny]));
					v[nx][ny] = true;
				}
			}
		}
		System.out.println(dist[n - 1][m - 1]);
	}
}
