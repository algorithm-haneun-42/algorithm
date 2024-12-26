import java.io.*;
import java.util.*;

public class MagicStar {
	static int[] arr;
	static boolean[] v;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new int[12];
		v = new boolean[13];
		int idx = 0;
		for (int i = 0; i < 5; i++) {
			String tmp = br.readLine();
			for (int j = 0; j < 9; j++) {
				char c = tmp.charAt(j);
				if (c == 'x') {
					arr[idx++] = 0;
				} else if (c != '.') {
					arr[idx++] = c - 'A';
					v[c - 'A'] = true;
				}
			}
		}
		recul();
	}
	static void recul() {
		if (check2(0, 3, 6, 10) &&
			check2(1, 2, 3, 4) &&
			check2(1, 5, 8, 11) &&
			check2(4, 6, 9, 11) &&
			check2(7, 8, 9, 10)) {
				System.out.println(Arrays.toString(arr));
				System.exit(0);
			}
		for (int i = 0; i < 12; i++) {
			if (arr[i] == 0) {
				for (int j = 1; j <= 12; j++) {
					if (!v[j]) {
						arr[i] = j;
						v[j] = true;
						recul();
						arr[i] = 0;
						v[j] = false;
					}
				}
			}
		}
	}
	static boolean check2(int a, int b, int c, int d) {
		if (arr[a] != 0 && arr[b] != 0 && arr[c] != 0 && arr[d] != 0) {
			if (arr[a] + arr[b] + arr[c] + arr[d] == 26) {
				return true;
			}
		}
		return false;
	}
}
