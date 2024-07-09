import java.io.*;
import java.util.*;

public class DescendingNumber {
	static List<Long> list = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if (n < 10) {
			System.out.println(n);
			return;
		}
		for (int i = 0; i < 10; i++) {
			set(i, 1);
		}
		if (n >= list.size()) {
			System.out.println(-1);
		} else {
			list.sort(Comparator.naturalOrder());
			System.out.println(list.get(n));
		}
	}
	static void set(long num, int val) {
		if (val > 10) return;

		list.add(num);
		for(int i = 0; i < num % 10; i++) {
			set((num * 10) + i, val + 1);
		}
	}
}
