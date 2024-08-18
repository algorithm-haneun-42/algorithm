import java.io.*;
import java.util.*;

public class WriteNum {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long n = Long.parseLong(st.nextToken());
		long k = Long.parseLong(st.nextToken());
		int i;
		long share = 0; int remainder = 0;
		long pre = 1;
		for (i = 1; i <= 10; i++) {
			long next = (long)(9 * Math.pow(10, i - 1) * i);
			if (pre <= k && k <= next) {
				share = (k - pre) / i;
				remainder = (int)((k - pre) % i);
				break;
			}
			pre = next + 1;
		}
		long target = (long)Math.pow(10, i - 1) + share;
		System.out.println(target);
		if (target > n) {
			System.out.println("-1");
			return;
		}
		System.out.println(Long.toString(target).charAt(remainder));
	}
}
