import java.io.*;
import java.util.*;

class CutLanCable1654 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());
		long[] arr = new long[n];
		for (int i = 0 ; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(arr);
		System.out.println(upperBound(arr, t) - 1);
	}
	static long upperBound(long[] arr, int target) {
		long lo = 0;
		long hi = arr[arr.length - 1] + 1;
		
		while (lo < hi) {
			long mid = lo + ((hi - lo) / 2);
			if (getCableCnt(arr, mid) >= target) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		return lo;
	}
	static long getCableCnt(long[] arr, long len) {
		long cnt = 0;
		for (int i = 0; i < arr.length; i++) {
			cnt += arr[i] / len;
		}
		return cnt;
	}
}