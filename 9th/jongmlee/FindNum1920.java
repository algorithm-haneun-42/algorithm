import java.io.*;
import java.util.*;

public class FindNum1920 {
	static StringTokenizer st;
	static int[] arr1;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		arr1 = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr1[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr1);
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			System.out.println(binarySearch(tmp));
		}
	}
	static int binarySearch(int target) {
		int lo = 0;
		int hi = arr1.length - 1;
		while (lo <= hi) {
			int mid = (hi + lo) / 2;
			if (arr1[mid] == target) {
				return 1;
			}
			if (arr1[mid] < target) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return 0;
	}
}
