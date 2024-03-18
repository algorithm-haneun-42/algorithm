import java.io.*;
import java.util.*;

public class VoteChairman2660 {
	static int v;
	static int[][] graph;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		v = Integer.parseInt(br.readLine());
		graph = new int[v + 1][v + 1];
		while (true) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			if (from == -1 && to == -1) {
				break;
			}
			graph[from][to] = 1;
			graph[to][from] = 1;
		}
		int min = Integer.MAX_VALUE;
		ArrayList<Integer> list = new ArrayList<>();
		for (int i = 1; i < v + 1; i++) {
			int score = bfs(i);
			if (score < min) {
				min = score;
				list.clear();
				list.add(i);
			} else if (score == min) {
				list.add(i);
			}
		}
		System.out.println(min + " " + list.size());
		list.forEach(x -> System.out.print(x + " "));
	}
	public static int bfs(int start) {
		Queue<int[]> q = new LinkedList<>();
		boolean[] visit = new boolean[v + 1];
		visit[start] = true;
		q.add(new int[]{start, 0});
		int max = 0;
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			for (int i = 1; i < v + 1; i++) {
				if (visit[i] || graph[cur[0]][i] == 0) continue;
				visit[i] = true;
				q.add(new int[]{i, cur[1] + 1});
				max = Math.max(cur[1] + 1, max);
			}
		}
		return max;
	}
}
