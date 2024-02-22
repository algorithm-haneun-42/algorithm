import java.io.*;
import java.util.*;

class LetsMakeSnowman20366 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int min = Integer.MAX_VALUE;
		for (int i = 0; i <= n - 4; i++) {
			for (int j = n - 1; j >= i + 3; j--) {
				int lo = i + 1;
				int hi = j - 1;
				int sm1 = arr[i] + arr[j];
				while (lo < hi) {
					int sm2 = arr[lo] + arr[hi];
					if (sm1 < sm2) {
						hi--;
					} else if (sm1 > sm2) {
						lo++;
					} else {
						System.out.println(0);
						return;
					}
					min = Math.min(Math.abs(sm1 - sm2), min);
				}
			}
		}
		System.out.println(min);
	}
}