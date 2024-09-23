import java.io.*;
import java.util.*;

public class RemoveBracket {
	static int bCnt;
	static String s;
	static TreeSet<String> answers = new TreeSet<>();
	static int[] answer;
	static Word[] arr;
	static class Word {
		char c;
		int n;
		boolean v;
		public Word(char c, int n) {
			this.c = c;
			this.n = n;
			this.v = false;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		arr = new Word[s.length()];
		int cnt = 1;
		for (int i = 0; i < s.length(); i++) {
			char tmp = s.charAt(i);
			arr[i] = new Word(tmp, 0);
			if (tmp == ')') {
				arr[i].n = cnt;
				for (int j = i; j >= 0; j--) {
					if (arr[j].c == '(' && !arr[j].v) {
						arr[j].n = cnt;
						arr[j].v = true;
						break;
					}
				}
				cnt++;
			}
		}
		bCnt = cnt - 1;
		for (int i = 1; i <= bCnt; i++) {
			answer = new int[i];
			recul(1, 0, i);
		}
		for (String x : answers) {
			System.out.println(x);
		}
	}
	static void recul(int start, int depth, int limit) {
		if (depth == limit) {
			StringBuilder sb = new StringBuilder();
			Set<Integer> set = new HashSet<>();
			for (int x : answer) {
				set.add(x);
			}
			for (int i = 0; i < arr.length; i++) {
				Word cur = arr[i];
				if (cur.c == '(' || cur.c == ')') {
					if (set.contains(cur.n)) {
						continue;
					}
				}
				sb.append(cur.c);
			}
			answers.add(sb.toString());
			return;
		}
		for (int i = start; i <= bCnt; i++) {
				answer[depth] = i;
				recul(i + 1, depth + 1, limit);
		}
	}
}
