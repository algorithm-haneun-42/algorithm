import java.util.*;
import java.io.*;

public class MusicProgram2623 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] indegreeCnt = new int[n + 1];
		List<List<Integer>> gragh = new ArrayList<List<Integer>>();
		for (int i = 0; i < n + 1; i++) {
			gragh.add(new ArrayList<>());
		}
		for  (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			List<Integer> list = new ArrayList<>();
			for (int j = 0; j < cnt; j++) {
				list.add(Integer.parseInt(st.nextToken()));
			}
			for (int j = 0; j < cnt - 1; j++) {
				int from = list.get(j);
				int to = list.get(j + 1);
				gragh.get(from).add(to);
				indegreeCnt[to]++;
			}
		}
		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i < n + 1; i++) {
			if (indegreeCnt[i] == 0) {
				q.add(i);
			}
		}
		StringBuilder sb = new StringBuilder();
		int cnt = 0;
		while (!q.isEmpty()) {
			int cur = q.poll();
			sb.append(cur).append('\n');
			cnt++;
			List<Integer> list = gragh.get(cur);
			for (int i = 0; i < list.size(); i++) {
				indegreeCnt[list.get(i)]--;
				if (indegreeCnt[list.get(i)] == 0) {
					q.add(list.get(i));
				}
			}
		}
		if (cnt != n) {
			System.out.println(0);
		}else {
			System.out.println(sb);
		}
	}
}
