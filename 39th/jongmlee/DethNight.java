import java.io.*;
import java.util.*;

public class DethNight {
	public static int[][] dir = {{-2, -1}, {-2, 1}, {0, -2}, {0, +2}, {2, -1}, {2, 1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		//(r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)
		StringTokenizer st = new StringTokenizer(br.readLine());
		int sx = Integer.parseInt(st.nextToken());
		int sy = Integer.parseInt(st.nextToken());
		int ex = Integer.parseInt(st.nextToken());
		int ey = Integer.parseInt(st.nextToken());
		boolean[][] v = new boolean[n][n];
		v[sx][sy] = true;
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[]{sx, sy, 0});
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			if (cur[0] == ex && cur[1] == ey) {
				System.out.println(cur[2]);
				return;
			}
			for (int i = 0; i < dir.length; i++) {
				int nx = cur[0] + dir[i][0];
				int ny = cur[1] + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !v[nx][ny]) {
					v[nx][ny] = true;
					q.add(new int[]{nx, ny, cur[2] + 1});
				}
			}
		}
		System.out.println(-1);
	}
}
