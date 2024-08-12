import java.io.*;
import java.util.*;

public class CommonDivisor {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long gcd = Long.parseLong(st.nextToken());
		long lcm = Long.parseLong(st.nextToken());
		long answer1 = gcd;
		long answer2 = lcm;
		long xy = gcd * lcm;

		for (long i = 2 * gcd; i * i <= xy; i += gcd) {
			if (xy % i == 0) {
				long tmp = xy / i;

				if (gcd(i, tmp) == gcd) {
					if (answer1 + answer2 > i + tmp) {
						answer1 = i;
						answer2 = tmp;
					}
				}
			}
		}

		System.out.println(answer1 + " " + answer2);
	}
	static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}