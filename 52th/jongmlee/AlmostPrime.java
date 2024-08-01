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
		prime[1] = true;
		getPrime();
		for (int i = 1; i <= 100000; i++) {
			if (!prime[i]) {
				System.out.print(i + " ");
			}
		}
	}
	public static void getPrime() {
		for (int i = 2; i * i < prime.length; i++) {
			if (!prime[i]) {
				for (int j = i * i; j < prime.length; j += i) {
					prime[j] = true;
				}
			}
		}
	}
}