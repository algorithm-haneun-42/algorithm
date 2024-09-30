import java.io.*;
import java.util.*;

public class SumOfNums {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		long k = Long.parseLong(st.nextToken());
		long arr[] = new long[n + 1];
		long pSum[] = new long[n + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			arr[i] = Long.parseLong(st.nextToken());
			pSum[i] = pSum[i - 1] + arr[i];
		}
		HashMap<Long, Integer> map = new HashMap<>();
		map.put(0L, 1);
		long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += map.getOrDefault(pSum[i] - k, 0);
			map.put(pSum[i], map.getOrDefault(pSum[i], 0) + 1);
		}
		System.out.println(cnt);
	}
}
