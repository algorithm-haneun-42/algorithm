import java.io.*;
import java.util.*;

public class NumCard10816 {
	static int[] arr;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			int lowerResult = lowerBound(tmp);
			int upperResult = upperBound(tmp);
			sb.append(upperResult - lowerResult).append(" ");
		}
		System.out.println(sb);
	}
	static int lowerBound(int target) {
		int lo = 0;
		int hi = arr.length;
		
		while (lo < hi) {
			int mid = lo + ((hi - lo) / 2);
			if (arr[mid] >= target) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return lo;
	}
	static int upperBound(int target) {
		int lo = 0;
		int hi = arr.length;
		
		while (lo < hi) {
			int mid = lo + ((hi - lo) / 2);
			if (arr[mid] > target) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		return lo;
	}
}
