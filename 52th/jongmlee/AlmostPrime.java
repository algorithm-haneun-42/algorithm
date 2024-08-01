import java.io.*;
import java.util.*;

class AlmostPrime {
	static boolean[] prime;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long a = Long.parseLong(st.nextToken());
		long b = Long.parseLong(st.nextToken());
		prime = new boolean[10000001];
		prime[0] = prime[1] = true;
		for (int i = 2; i * i < prime.length; i++) {
			if (!prime[i]) {
				for (int j = i * i; j < prime.length; j += i) {
					prime[j] = true;
				}
			}
		}
		int answer = 0;
		for (int i = 2; i < prime.length; i++) {
			if (!prime[i]) {
				long tmp = i;
				while (tmp <= b / i) {
					if (a <= tmp * i) {
						System.out.println("i = " + i + ", tmp = " + tmp);
						answer++;
					}
					tmp *= i;
				}
			}
		}
		System.out.println(answer);
	}
}