import java.io.*;
import java.util.*;

public class LongestEvenContinuousPartialSequence22862 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int p1 = 0;
		int p2 = 0;
		int maxLen = -1;
		int OddCnt = 0;
		for (; p2 < n; p2++) {
			if (arr[p2] % 2 == 1) {
				OddCnt++;
			}
			if (OddCnt > k) {
				maxLen = Math.max((p2 - p1) - (OddCnt - 1), maxLen);
				for (; arr[p1] % 2 == 0; p1++);
				--OddCnt;
				++p1;
			}
		}
		maxLen = Math.max(p2 - p1 - OddCnt, maxLen);
		System.out.println(maxLen);
	}
}
