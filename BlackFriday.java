import java.io.*;
import java.util.*;

public class BlackFriday {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for (int  i =0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int answer = 0;
		// 바깥쪽 루프
		loop:
		for (int i = n - 1; i >= 0; i--) {
			int target = c - arr[i];
			// 한개로 통과하는 경우
			if (target == 0) {
				answer = 1;
				break;
			} else if (target > 0) {
				// 두개로 통과하는 경우
				for (int j = 0; j < i; j++) {
					if (arr[j] == target) {
						answer = 1;
						break loop;
					}
				}
				// 세개로 통과하는 경우 (투포인터)
				int lo = 0;
				int hi = i - 1;
				while (lo < hi) {
					// 1 2 3 4 5
					int sum = arr[lo] + arr[hi];
					if (sum == target) {
						answer = 1;
						break loop;
					}
					if (sum < target) {
						lo++;
						continue;
					}
					hi--;
				}
			}
		}
		System.out.println(answer);
	}
}