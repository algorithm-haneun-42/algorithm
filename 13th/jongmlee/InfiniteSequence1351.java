import java.io.*;
import java.util.*;

public class InfiniteSequence1351 {
	static HashMap<Long, Long> map;
	static long p, q;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long n = Long.parseLong(st.nextToken());
		p = Long.parseLong(st.nextToken());
		q = Long.parseLong(st.nextToken());
		map = new HashMap<>();
		map.put(0L, 1L);
		System.out.println(recul(n));
	}
	static long recul(long n) {
		if (n == 0) {
			return map.get(0L);
		}
		long tmp1 = map.containsKey(n / p) ? map.get(n / p) : recul(n / p);
		long tmp2 = map.containsKey(n / q) ? map.get(n / q) : recul(n / q);
		return tmp1 + tmp2;
	}
}
