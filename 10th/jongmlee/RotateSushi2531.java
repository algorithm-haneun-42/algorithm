import java.io.*;
import java.util.*;

class RotateSushi2531 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); // 접시의 수
		int d = Integer.parseInt(st.nextToken()); // 초밥의 가짓수
		int k = Integer.parseInt(st.nextToken()); // 연속해서 먹는 접시의 수
		int c = Integer.parseInt(st.nextToken()); // 쿠폰 번호
		int[] table = new int[n];
		for (int i = 0; i < n; i++) {
			table[i] = Integer.parseInt(br.readLine());
		}
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < k; i++) {
			map.put(table[i], map.getOrDefault(table[i], 0) + 1);
		}
		int p1 = 0;
		int p2 = k - 1;
		int preP1 = p1;
		int cnt = map.size();
		if (!map.containsKey(c)) cnt++;
		p1++;
		p2++;
		while (!(p1 == 0 && p2 == k - 1)) {
			map.put(table[preP1], map.get(table[preP1]) - 1);
			if (map.get(table[preP1]) == 0) map.remove(table[preP1]);
			map.put(table[p2], map.getOrDefault(table[p2], 0) + 1);
			int tmp = map.size();
			if (!map.containsKey(c)) tmp++;
			cnt = Math.max(tmp, cnt);
			if (cnt == d) break;
			preP1 = p1;
			p1 = p1 + 1 == n ? 0 : p1 + 1;
			p2 = p2 + 1 == n ? 0 : p2 + 1;
		}
		System.out.println(cnt);
	}
}