import java.io.*;
import java.util.*;

public class EntryScreening {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		long lo = 0;
		long hi = Long.MAX_VALUE;
		while (lo < hi) {
			long mid = (hi + lo) / 2;
			long sum = 0;
			for (int i = 0; i < n; i++) {
				sum += mid / arr[i];
				if (sum < 0) {
					sum = m + 1;
					break;
				}
			}
			if (sum >= m) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		System.out.println(lo);
	}
}
