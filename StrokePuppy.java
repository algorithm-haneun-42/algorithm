import java.io.*;
import java.util.*;

public class StrokePuppy {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		if (n == m) {
			System.out.println(0);
			return;
		}
		for (long base = 1, gap = m - n; ; base++) {
			long sum = (base * base) + base;
			if (sum < gap) continue;
			System.out.println(base * 2 + (sum - base >= gap ? -1 : 0));
			return;
		}
	}
}
