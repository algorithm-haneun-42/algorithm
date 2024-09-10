import java.io.*;
import java.util.*;

public class Pizza {
	static int d, n, pos;
	static int[] oven;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		d = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		oven = new int[d + 1];
		st = new StringTokenizer(br.readLine());
		oven[0] = Integer.MAX_VALUE;
		for (int i = 1; i < d + 1; i++) {
			oven[i] = Integer.parseInt(st.nextToken());
			oven[i] = Math.min(oven[i - 1], oven[i]);
		}

		st = new StringTokenizer(br.readLine());
		pos = d;
		for (int i = 0; i < n; i++) {
			int size = Integer.parseInt(st.nextToken());
			drop(size);
		}

		System.out.println(pos);
	}

	private static void drop(int size) {
		boolean flag = false;

		for (int i = pos; i > 0; i--) {
			if (size <= oven[i]) {
				pos = i;
				oven[i] = 0;
				flag = true;
				break;
			}
		}

		if (!flag) {
			pos = 0;
		}
	}
}