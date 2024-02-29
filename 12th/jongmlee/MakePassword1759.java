import java.io.*;
import java.util.*;

public class MakePassword1759 {
	static int l, c, vowelCnt, consonantCnt;
	static char[] arr, pwd;
	static StringBuilder sb = new StringBuilder();
	static char[] vowels = {'a', 'e', 'i', 'o', 'u'};
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		l = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		arr = br.readLine().replace(" ", "").toCharArray();
		pwd = new char[l];
		Arrays.sort(arr);
		reculsion(0, 0);
		System.out.println(sb);
	}
	static void reculsion(int idx, int depth) {
		if (depth == l) {
			if (vowelCnt >= 1 && consonantCnt >= 2) {
				sb.append(pwd).append("\n");
			}
			return ;
		}
		for (int i = idx; i < c; i++) {
			pwd[depth] = arr[i];
			check(pwd[depth], false);
			reculsion(i + 1, depth + 1);
			check(pwd[depth], true);
		}
	}
	static void check(char c, boolean flag) {
		for (char v : vowels) {
			if (v == c) {
				if (!flag) vowelCnt++;
				else vowelCnt--;
				return ;
			}
		}
		if (!flag) consonantCnt++;
		else consonantCnt--;
	}
}
