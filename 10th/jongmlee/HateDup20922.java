import java.io.*;
import java.util.*;

public class HateDup20922 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); // 수열의 길이
		int k = Integer.parseInt(st.nextToken()); // 같은 원소의 최대 개수
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int[] cnt = new int[100011];
		int maxLen = -1;
		int p1 = 0;
		int p2 = 0;
		for (p1 = 0; p1 < n; p1++) {
			cnt[arr[p1]]++;
			if (cnt[arr[p1]] > k) {
				maxLen = Math.max(p1 - p2, maxLen);
				for (; arr[p2] != arr[p1]; p2++) {
					--cnt[arr[p2]];
				}
				--cnt[arr[p2]];
				++p2;
			}
		}
		maxLen = Math.max(p1 - p2, maxLen);
		System.out.println(maxLen);
	}
}
