import java.io.*;
import java.util.*;

public class MergeFileThree13975 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		long ans;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			PriorityQueue<Long> pq = new PriorityQueue<>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				pq.add(Long.parseLong(st.nextToken()));
			}
			ans = 0;
			while (pq.size() > 1) {
				long sum = pq.poll() + pq.poll();
				ans += sum;
				pq.add(sum);
			}
			System.out.println(ans);
		}
	}
}
