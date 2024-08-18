import java.io.*;
import java.util.*;

public class Worldcup {
	static int[][][] results;
	static int[][] cur;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		results = new int[4][6][3];
		for (int i = 0; i < 4; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 3; k++) {
					results[i][j][k] = Integer.parseInt(st.nextToken());
				}
			}
		}
		cur = new int[6][3];
		recul(0, 0, 0, 0);
	}
	static void recul(int start, int depth, int n1, int n2) {
		if (depth == 2) {
			// 되는지 확인
			recul2()
			return;
		}
		for (int i = start; i < 6; i++) {
			if (depth == 0) {
				recul(i + 1, depth + 1, i, 0);
			} else if (depth == 1) {
				recul(i + 1, depth + 1, n1, i);
			}
		}
	}
}
