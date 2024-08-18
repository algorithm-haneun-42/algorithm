import java.io.*;
import java.util.*;

public class Snail {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long m = Long.parseLong(st.nextToken());
		long n = Long.parseLong(st.nextToken());
		long cnt = 0;
		long x = 0, y = 0;
		if(m > n) {
			cnt = (n - 1) * 2 + 1;
		}else {
			cnt = (m - 1) * 2;
		}
		if(m == n) {
			if(m % 2 == 1) {
				x = m / 2 + 1;
				y = n / 2 + 1;
			}else {
				x = m / 2 + 1;
				y = n / 2;
			}
	 	}else if (m > n) {
	 		if(n % 2 == 0) {
				x = n / 2 + 1;
				y = n / 2;
	 		}else {
				x = n / 2 + 1 + (m - n);
				y = n / 2 + 1;
	 		}
	 	}else {
	 		if(m % 2 == 0) {
				x = m / 2 + 1;
				y = m / 2;
	 		}else {
				x = m / 2 + 1;
				y = m / 2 + 1 + (n - m);
	 		}
	 	}
		System.out.println(cnt);
		System.out.println(x + " " + y);
	}
}
