import java.io.*;
import java.util.*;

public class StartingLine {
	static int max = 0;
	static int[][] arr;
	static int[] nums;
	static boolean[] v;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer st;
		while (t-- > 0) {
			arr = new int[11][11];
			nums = new int[11];
			v = new boolean[11];
			for (int i = 0; i < 11; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 11; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			dfs(0);
			System.out.println(max);
			max = 0;
		}
	}
	static void dfs(int depth) {
		if (depth == 11) {
			int sum = 0;
			for (int i = 0; i < 11; i++) {
				sum += arr[nums[i]][i];
			}
			max = Math.max(sum, max);
		}
		for (int i = 0; i < 11; i++) {
			if (!v[i] && arr[i][depth] > 0) {
				nums[depth] = i;
				v[i] = true;
				dfs(depth + 1);
				v[i] = false;
			}
		}
	}
}
