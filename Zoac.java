import java.io.*;
import java.util.*;

public class Zoac {
	static String s;
	static boolean[] v;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		v = new boolean[s.length()];
		zoac(0, s.length() - 1);
		System.out.println(sb.toString());
	}
	
	static void zoac(int left, int right) {
		if (left > right) return;

		int idx = left;

		for (int i = left; i <= right; i++) {
			if (s.charAt(idx) > s.charAt(i)) {
				idx = i;
			}
		}
		v[idx] = true;

		for (int i = 0; i < s.length(); i++) {
			if (v[i]) {
				sb.append(s.charAt(i));
			}
		}
		sb.append("\n");

		zoac(idx + 1, right);
		zoac(left, idx - 1);
	}
}
