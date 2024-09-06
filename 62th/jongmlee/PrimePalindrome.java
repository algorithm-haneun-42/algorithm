import java.io.*;
import java.util.*;

public class PrimePalindrome {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		StringBuilder sb = new StringBuilder();
		for (int i = a; i <= b; i++) {
			if (isPalindrome(i)) {
				if (isPrime(i)) {
					sb.append(i).append('\n');
				}
			}
		}
		sb.append(-1);
		System.out.println(sb);
	}
	static boolean isPrime(int num) {
		for(int i = 2 ; i <= Math.sqrt(num); i++) {
			if(num % i == 0) {
				return false;
			}
		}
		return true;
	}
	static boolean isPalindrome(int num) {
		String s = Integer.toString(num);
		int lo = 0;
		int hi = s.length() - 1;
		while (lo <= hi) {
			if (s.charAt(lo) != s.charAt(hi)) {
				return false;
			}
			lo++;
			hi--;
		}
		return true;
	}
}
