import java.io.*;
import java.util.*;

public class LongestEvenSequence {
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
		int s = 0;
		int e = 0;
		int cnt = arr[0] % 2 == 1 ? 1 : 0; // 홀수 갯수
		int max = arr[0] % 2 == 1 ? 0 : 1;
		while (s <= e) {
			if (cnt > k) {
				cnt = arr[s] % 2 == 1 ? cnt - 1 : cnt;
				s++;
			} else {
				if (e + 1 >= n) break;
				e++;
				cnt = arr[e] % 2 == 1 ? cnt + 1 : cnt;
				max = Math.max(e - s + 1 - cnt, max);
			}
		}
		System.out.println(max);
	}
}
