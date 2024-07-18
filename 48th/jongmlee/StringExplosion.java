import java.io.*;
import java.util.*;

public class StringExplosion {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		String target = br.readLine();
		char e = target.charAt(target.length() - 1);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			sb.append(c);
			if (c == e && target.length() <= sb.length()) {
				boolean flag = false;
				for (int j = 0; j < target.length(); j++) {
					if (target.charAt(j) != sb.charAt(sb.length() - target.length() + j)) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					sb.delete(sb.length() - target.length(), sb.length());
				}
			}
		}
		if (sb.length() == 0) {
			System.out.println("FRULA");
		} else {
			System.out.println(sb);
		}
	}
}
