import java.io.*;
import java.util.*;

public class ProblemRecommendSystem21939 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		TreeSet<Problem> ts = new TreeSet<>();
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			ts.add(new Problem(x, y));
			map.put(x, y);
		}
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			String oper = st.nextToken();
			if (oper.equals("recommend")) {
				int x = Integer.parseInt(st.nextToken());
				if (x == 1) {
					sb.append(ts.last().idx);
				} else {
					sb.append(ts.first().idx);
				}
				sb.append('\n');
			} else if (oper.equals("add")) {
				int p = Integer.parseInt(st.nextToken());
				int l = Integer.parseInt(st.nextToken());
				ts.add(new Problem(p, l));
				map.put(p, l);
			} else if (oper.equals("solved")) {
				int p = Integer.parseInt(st.nextToken());
				int l = map.get(p);
				ts.remove(new Problem(p, l));
				map.remove(p);
			}
		}
		System.out.println(sb);
	}
	static class Problem implements Comparable<Problem>{
		int idx;
		int difficulty;
		public Problem(int idx, int difficulty) {
			this.idx = idx;
			this.difficulty = difficulty;
		}
		@Override
		public int compareTo(Problem o) {
			if (this.difficulty == o.difficulty) {
				return this.idx - o.idx;
			}
			return this.difficulty - o.difficulty;
		}
	}
}
