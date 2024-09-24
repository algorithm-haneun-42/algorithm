import java.io.*;
import java.util.*;

public class StringGame {
	static String s;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			s = br.readLine();
			int k = Integer.parseInt(br.readLine());
			boolean flag = false;
			for (int i = k; i <= s.length(); i++) {
				if (slide(i, k)) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				System.out.println(-1);
			}
			for (int i = s.length(); i >= k; i--) {
				if (slide(i, k)) break;
			}
			System.out.println();
		}
	}
	public static boolean slide(int size, int k) {
		int lo = 0;
		int hi = size - 1;
		int[] alphabet = new int[26];
		for (int i = lo; i <= hi; i++) {
			alphabet[s.charAt(i) - 'a']++;
		}
		for (int i = 0; i < alphabet.length; i++) {
			if (alphabet[i] == k && s.charAt(lo) == s.charAt(hi)) {
				System.out.print(size + " ");
				return true;
			}
		}
		lo++;
		hi++;
		while (hi < s.length()) {
			//System.out.println(Arrays.toString(alphabet));
			alphabet[s.charAt(lo - 1) - 'a']--;
			alphabet[s.charAt(hi) - 'a']++;
			if (alphabet[s.charAt(hi) - 'a'] == k) {
				if (s.charAt(lo) == s.charAt(hi)) {
					System.out.print(size + " ");
					return true;
				}
			}
			lo++;
			hi++;
		}
		return false;
	}
}
