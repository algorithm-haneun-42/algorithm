import java.io.*;
import java.util.*;

public class DoublyPriorityQueue7662 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			TreeMap<Integer, Integer> tm = new TreeMap<>();
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				char oper = st.nextToken().charAt(0);
				int element = Integer.parseInt(st.nextToken());
				if (oper == 'I') {
					tm.put(element, tm.getOrDefault(element, 0) + 1);
				} else {
					if (tm.isEmpty()) {
						continue;
					}
					int tmp = (element == 1) ? tm.lastKey() : tm.firstKey();
					if (tm.put(tmp, tm.get(tmp) - 1) == 1) {
						tm.remove(tmp);
					}
				}
			}
			if (tm.isEmpty()) {
				System.out.println("EMPTY");
			} else {
				System.out.print(tm.lastKey() + " " + tm.firstKey());
				System.out.println();
			}
		}
	}
}
