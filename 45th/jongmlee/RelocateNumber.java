import java.io.*;
import java.util.*;

public class RelocateNumber {
	static char[] arr;
	static String A;
	static int B;
	static boolean[] v;
	static int answer = -1;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		A = st.nextToken();
		B = Integer.parseInt(st.nextToken());
		arr = new char[A.length()];
		v = new boolean[A.length()];
		recul(0);
		System.out.println(answer);
	}
	static void recul(int depth) {
		if (depth == A.length()) {
			int tmp = Integer.parseInt(new String(arr));
			if (tmp < B && answer < tmp) {
				answer = tmp;
			}
			return;
		}
		for (int i = 0; i < A.length(); i++) {
			if (depth == 0 && A.charAt(i) == '0') continue;
			if (!v[i]) {
				arr[depth] = A.charAt(i);
				v[i] = true;
				recul(depth + 1);
				v[i] = false;
			}
		}
	}
}
