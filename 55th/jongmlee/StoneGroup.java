import java.io.*;
import java.util.*;

public class StoneGroup {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int sum = A + B + C;
		if (sum % 3 != 0) {
			System.out.println(0);
			return;
		}
		boolean[][] v = new boolean[sum + 1][sum + 1];
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[]{A, B, C});
		v[A][B] = true;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			if (cur[0] == cur[1] && cur[1] == cur[2]) {
				System.out.println(1);
				return;
			}
			if (cur[0] != cur[1]) {
				int nx = cur[0] > cur[1] ? cur[0] - cur[1] : cur[0] + cur[0];
				int ny = cur[0] > cur[1] ? cur[1] + cur[1] : cur[1] - cur[0];
				if(!v[nx][ny]){
					v[nx][ny] = true;
					q.offer(new int[]{nx, ny, cur[2]});
				}
			}
			if (cur[1] != cur[2]) {
				int ny = cur[1] > cur[2] ? cur[1] - cur[2] : cur[1] + cur[1];
				int nz = cur[1] > cur[2] ? cur[2] + cur[2] : cur[2] - cur[1];
				if(!v[ny][nz]){
					v[ny][nz] = true;
					q.offer(new int[]{cur[0], ny, nz});
				}
			}
			if (cur[0] != cur[2]) {
				int nx = cur[0] > cur[2] ? cur[0] - cur[2] : cur[0] + cur[0];
				int nz = cur[0] > cur[2] ? cur[2] + cur[2] : cur[2] - cur[0];
				if(!v[nx][nz]){
					v[nx][nz] = true;
					q.offer(new int[]{nx, cur[1], nz});
				}
			}
		}
		System.out.println(0);
	}
}
