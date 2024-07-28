import java.io.*;
import java.util.*;

public class Teaching {
	static int n, k, max;
	static String[] words;
	static List<Character> list;
	static boolean[] v;
	public static void main(String[] args) throws IOException {
		//antic
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		if (k < 5) {
            System.out.println(0);
            return;
        } else if (k == 26) {
            System.out.println(n);
            return;
        }
		words = new String[n];
		Set<Character> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String tmp = br.readLine();
			words[i] = tmp.substring(4, tmp.length() - 4);
			for (int j = 0; j < words[i].length(); j++) {
				set.add(words[i].charAt(j));
			}
		}
		list = new ArrayList<>();
		for (Character c : set) {
			list.add(c);
		}
		v = new boolean[26];
		v['a' - 'a'] = true;
        v['n' - 'a'] = true;
        v['t' - 'a'] = true;
        v['i' - 'a'] = true;
        v['c' - 'a'] = true;
		recul(0, 0);
		System.out.println(max);
	}
	static void recul(int start, int depth) {
		if (depth == k - 5) {
			int cnt = 0;
			for (String s : words) {
				boolean flag = true;
				for (int i = 0; i < s.length(); i++) {
					char c = s.charAt(i);
					if (!v[c - 'a']) {
						flag = false;
						break;
					}
				}
				if (flag) cnt++;
			}
			max = Math.max(cnt, max);
			return;
		}
		for (int i = start; i < list.size(); i++) {
			if (!v[list.get(i) - 'a']) {
				v[list.get(i) - 'a'] = true;
				recul(i, depth + 1);
				v[list.get(i) - 'a'] = false;
			}
		}
	}
}
