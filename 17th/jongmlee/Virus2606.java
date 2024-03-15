import java.io.*;
import java.util.*;

public class Virus2606 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int v = Integer.parseInt(br.readLine());
		int e = Integer.parseInt(br.readLine());
		int[][] graph = new int[v + 1][v + 1];
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			graph[from][to] = 1;
			graph[to][from] = 1;
		}
		boolean[] visit = new boolean[v + 1];
		Queue<Integer> q = new LinkedList<>();
		visit[1] = true;
		q.add(1);
		int cnt = 0;
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int i = 1; i < v + 1; i++) {
				if (visit[i]) continue;
				if (graph[cur][i] == 0) continue;
				visit[i] = true;
				q.add(i);
				cnt++;
			}
		}
		System.out.println(cnt);
	}
}
