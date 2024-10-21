import java.io.*;
import java.util.*;

public class Henry {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			long a = Long.parseLong(st.nextToken());
			long b = Long.parseLong(st.nextToken());
			// 10/14 - 7/14 = 3/14, 15/70 - 14/70 = 1/70
			long div = 2;
			while (a > 1) {
				long lcm = lcm(div, b);
				//System.out.println(lcm);
				if (lcm / div <= a * (lcm / b)) {
					a = (a * (lcm / b)) - (lcm / div);
					b = lcm;
					//System.out.println(a + " " + b);
					long gcd = gcd(a, b);
					if (gcd > 1) {
						a /= gcd;
						b /= gcd;
					}
				}
				div++;
			}
			System.out.println(b);
		}
	}
	static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
	static long lcm(long a, long b) {
		return (a * b) / gcd(a, b);
	}
}
