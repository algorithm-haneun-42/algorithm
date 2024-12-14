import java.io.*;
import java.util.*;


public class PalindromeIsNotPalindrome {
	static char[] s;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine().toCharArray();
		if (isPalindrome(0, s.length - 1)) {
			if (isAllOneChar()) {
				System.out.println(-1);
			} else {
				System.out.println(s.length - 1);
			}
		} else {
			System.out.println(s.length);
		}
	}
	public static boolean isPalindrome(int start, int end) {
		int len = end - start + 1;
		for (int i = 0; i < len / 2; i++) {
			if (s[i] != s[end - i]) {
				return false;
			}
		}
		return true;
	}
	static boolean isAllOneChar() {
		for (int i = 1; i < s.length; i++) {
			if (s[0] != s[i]) {
				return false;
			}
		}
		return true;
	}
}
