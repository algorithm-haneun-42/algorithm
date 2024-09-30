import java.io.*;
import java.util.*;

public class StackingDice {
	static int max = -1, n;
	static int[][] arr;
	static int[] pairArr = {5, 3, 4, 1, 2, 0};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		n = Integer.parseInt(br.readLine());
		arr = new int[n][6];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 6; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for (int i = 0; i < 6; i++) {
			recul(1, i, 0);
		}
		System.out.println(max);
	}
	static void recul(int cnt, int bottom, int sum) {
		int pair = pairArr[bottom];
		int tempMax = -1;
		for (int i = 0; i < 6; i++) {
			if (i == pair || i == bottom) {
				continue;
			}
			tempMax = Math.max(tempMax, arr[cnt - 1][i]);
		}
		sum += tempMax;
		if (cnt == n) {
			max = Math.max(max, sum);
			return;
		}
		for (int i = 0; i < 6; i++) {
			if (arr[cnt - 1][pair] == arr[cnt][i]) {
				recul(cnt + 1, i, sum);
				break;
			}
		}
	}
}
