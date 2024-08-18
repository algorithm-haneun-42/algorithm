import java.io.*;
import java.util.*;

public class Theif {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			int[] arr = new int[n];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			int lo = 0;
			int hi = m;
			int sum = 0;
			for (int i = lo; i < hi; i++) {
				sum += arr[i];
			}
			int cnt = sum < k ? 1 : 0;
			if (n == m) {
				System.out.println(cnt);
				continue;
			}
			while (lo < n - 1) {
				sum -= arr[lo];
				sum += arr[hi];
				if (sum < k) cnt++;
				lo++;
				hi = (hi + 1) % n;
				
			}
			System.out.println(cnt);
		}
	}
}
