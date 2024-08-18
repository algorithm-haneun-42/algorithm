import java.io.*;
import java.util.*;

public class Palindrome {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		loop:
		for (int i = 0; i < n; i++) {
			char[] cur = br.readLine().toCharArray();
			System.out.println(check(0, cur.length - 1, cur, 0));
		}
	}
	static int check(int lo, int hi, char[] cur, int cnt) {
		while (lo < hi) {
			if (cur[lo] == cur[hi]) {
				lo++; hi--;
				continue;
			}
			if (cnt == 0) {
				if (cur[lo + 1] == cur[hi]) {
					if (check(lo + 1, hi, cur, cnt + 1) == 1) return 1;
				}
				if (cur[lo] == cur[hi - 1]) {
					return check(lo, hi - 1, cur, cnt + 1);
				}
			}
			return 2;
		}
		if (cnt == 0) {
			return 0;
		} else {
			return 1;
		}
	}
}
