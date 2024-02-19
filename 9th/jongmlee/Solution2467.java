import java.io.*;
import java.util.*;

public class Solution2467 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int lo = 0;
		int hi = n - 1;
		int ans = Integer.MAX_VALUE;
		int tmpLo = 0;
		int tmpHi = 0;
		while (lo < hi) {
			int val = arr[lo] + arr[hi];
			if (val == 0) {
				System.out.println(arr[lo] + " " + arr[hi]);
				return;
			}
			if (Math.abs(val) < ans) {
				ans = Math.abs(val);
				tmpLo = lo;
				tmpHi = hi;
			}
			if (val < 0) {
				lo++;
			} else {
				hi--;
			}
		}
		System.out.println(arr[tmpLo] + " " + arr[tmpHi]);
	}
}
