import java.io.*;
import java.util.*;

public class AandB {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		String t = br.readLine();
		recul(s, t);
		System.out.println(0);
	}
	static void recul(String s, String t) {
		if (s.length() == t.length()) {
			if (s.equals(t)) {
				System.out.println(1);
				System.exit(0);
			} else {
				return;
			}
		}
		StringBuilder sb = new StringBuilder(t);
		if (sb.charAt(sb.length() - 1) == 'A') {
			recul(s, sb.deleteCharAt(sb.length() - 1).toString());
		}
		sb = new StringBuilder(t);
		if (sb.charAt(0) == 'B') {
			recul(s, sb.reverse().deleteCharAt(sb.length() - 1).toString());
		}
	}
	// AAB
}
