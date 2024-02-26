import java.io.*;
import java.util.*;

public class StartAndLink14889 {
	static int n;
	static int[][] map;
	static boolean[] v;
	static int min = Integer.MAX_VALUE;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		v = new boolean[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		combination(0, 0);
		System.out.println(min);
	}
	static void combination(int idx, int depth) {
		if(depth == n / 2) {
			getDiff();
			return;
		}
		for(int i = idx; i < n; i++) {
			if(!v[i]) {
				v[i] = true;
				combination(i + 1, depth + 1);
				v[i] = false;
			}
		}
	}
	static void getDiff() {
		int start = 0;
		int link = 0;
 
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (v[i] == true && v[j] == true) {
					start += map[i][j];
					start += map[j][i];
				}
				else if (v[i] == false && v[j] == false) {
					link += map[i][j];
					link += map[j][i];
				}
			}
		}
		int val = Math.abs(start - link);
		
		if (val == 0) {
			System.out.println(val);
			System.exit(0);
		}
		
		min = Math.min(val, min);
	}
}
