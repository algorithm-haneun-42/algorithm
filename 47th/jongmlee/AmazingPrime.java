import java.io.*;
import java.util.*;

public class AmazingPrime {
	static int n;
	public static void main(String[] args) throws IOException {
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		recul(0, 0);
	}
	static void recul(int num, int depth) {
		if (depth == n) {
			System.out.println(num);
		}
		for (int i = 1; i < 10; i++) {
			int tmp = 10 * num + i;
			if (isPrime(tmp)) {
				recul(tmp, depth + 1);
			}
		}
	}
	static boolean isPrime(int num) {
		if(num < 2) return false;
		for(int i = 2 ; i * i <= num; i++) {
			if(num % i == 0) {
				return false;
			}
		}
		return true;
	}
}
