import java.io.*;
import java.util.*;


public class LetterOfIndustrySpy {
	static int MAX = 10000001;
	static boolean[] primeArr = new boolean[MAX]; // false면 소수
	static boolean[] v;
	static String s;
	static StringBuilder sb;
	static Set<Integer> set;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		eratosthenese();

		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			s = br.readLine();
			sb = new StringBuilder();
			set = new HashSet<>();
			int length = s.length();
			v = new boolean[length];
			for (int i = 1; i <= length; i++) {
				combination(i, "");
			}

			System.out.println(set.size());
		}
	}

	private static void combination(int depth, String cur) {
		if (depth == 0) {
			if (primeArr[Integer.parseInt(cur)]) {
				set.add(Integer.parseInt(cur));
			}
			return;
		}

		for (int i = 0; i < s.length(); i++) {
			if (!v[i]) {
				v[i] = true;
				combination(depth - 1, cur + s.charAt(i));
				v[i] = false;
			}
		}
	}

	private static void eratosthenese() {
		Arrays.fill(primeArr, true);
		primeArr[0] = primeArr[1] = false;
		for (int i = 2; i < Math.sqrt(MAX); i++) {
			if (primeArr[i]) {
				for (int j = i * i; j < MAX; j += i) {
					primeArr[j] = false;
				}
			}
		}
	}
}
