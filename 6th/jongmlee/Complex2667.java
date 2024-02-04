import java.io.*;
import java.util.*;

class Complex2667 {
	static int n, cnt;
	static PriorityQueue<Integer> pq = new PriorityQueue<>();
	static Queue<Pos> q = new LinkedList<>();
	static int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	static int[][] map;
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < n; j++) {
				map[i][j] = line.charAt(j) - '0';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					map[i][j] = 0;
					q.add(new Pos(i, j));
					pq.add(bfs());
					cnt++;
				}
			}
		}
		System.out.println(cnt);
		while (!pq.isEmpty()) {
			System.out.println(pq.poll());
		}
	}
	public static int bfs() {
		int ret = 1;
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dir[i][0];
				int ny = cur.y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 1) {
					map[nx][ny] = 0;
					q.add(new Pos(nx, ny));
					ret++;
				}
			}
		}
		return ret;
	}
	static class Pos {
		int x;
		int y;
		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}