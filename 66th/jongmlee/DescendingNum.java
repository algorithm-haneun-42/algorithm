import java.io.*;
import java.util.*;

public class DescendingNum {
	static int n;
	static int[] arr = {9,8,7,6,5,4,3,2,1,0};
	static List<Long> list = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if (n > 1023) {
			System.out.println(-1);
			return;
		}

		dfs(0, 0);
		list.sort(Comparator.naturalOrder());

		System.out.println(list.get(n - 1));
	}
	static void dfs(long num, int idx) {
		if (!list.contains(num)) {
			list.add(num);
		}

		if (idx >= 10) {
			return;
		}

		dfs((num * 10) + arr[idx], idx + 1);
		dfs(num, idx + 1);
	}
}
