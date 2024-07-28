import java.util.*;
import java.io.*;

public class NumberList {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		loop:
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			List<String> list = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				list.add(br.readLine());
			}
			list.sort(Comparator.naturalOrder());
			for (int i = 1; i < list.size(); i++) {
				if (list.get(i).startsWith(list.get(i - 1))) {
					System.out.println("NO");
					continue loop;
				}
			}
			System.out.println("YES");
		}
	}
}
