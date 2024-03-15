import java.io.*;
import java.util.*;

public class FindPath11403 {
	static int v;
	static int[][] graph;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		v = Integer.parseInt(br.readLine());
		graph = new int[v + 1][v + 1];
		for (int i = 1; i < v + 1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < v + 1; j++) {
				graph[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < v + 1; i++) {
			for (int j = 1; j < v + 1; j++) {
				sb.append(bfs(i, j)).append(' ');
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
	public static int bfs(int from, int to) {
		boolean[] visit = new boolean[v + 1];
		Queue<Integer> q = new LinkedList<>();
		q.add(from);
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int i = 1; i < v + 1; i++) {
				if (visit[i]) continue;
				if (graph[cur][i] == 0) continue;
				visit[i] = true;
				q.add(i);
			}
		}
		return visit[to] ? 1 : 0;
	}
}
