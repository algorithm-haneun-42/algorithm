import java.io.*;
import java.util.*;

public class ThreeFriends {
	static int answer = Integer.MAX_VALUE;
	static int n, m;
	static boolean[][] arr;
	static int[] sum;
	static int[] tmp = new int[3];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new boolean[n + 1][n + 1];
		sum = new int[n + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			arr[from][to] = true;
			arr[to][from] = true;
			sum[from]++;
			sum[to]++;
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = i + 1; j < n + 1; j++) {
				if (arr[i][j]) {
					for (int k = j + 1; k < n + 1; k++) {
						if (arr[i][k] && arr[j][k]) {
							answer = Math.min(answer, sum[i] + sum[j] + sum[k] - 6);
						}
					}
				}
			}
		}
		System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
	}
}
