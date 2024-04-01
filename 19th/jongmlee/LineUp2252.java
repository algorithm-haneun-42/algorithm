import java.io.*;
import java.util.*;

public class LineUp2252 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] indegreeCnt = new int[n + 1];
		List<List<Integer>> gragh = new ArrayList<List<Integer>>();
		for (int i = 0; i < n + 1; i++) {
			gragh.add(new ArrayList<Integer>());
		}
		for (int i = 0 ; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			gragh.get(from).add(to);
			indegreeCnt[to]++;
		}
		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i < n + 1; i++) {
			if (indegreeCnt[i] == 0) {
				q.add(i);
			}
		}
		StringBuilder sb = new StringBuilder();
		while (!q.isEmpty()) {
			int cur = q.poll();
			sb.append(cur).append(' ');
			List<Integer> list = gragh.get(cur);
			for (int i = 0; i < list.size(); i++) {
				indegreeCnt[list.get(i)]--;
				if (indegreeCnt[list.get(i)] == 0) {
					q.add(list.get(i));
				}
			}
		}
		System.out.println(sb);
	}
}
