import java.io.*;
import java.util.*;

public class Lie1043 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); // 사람 수
		int m = Integer.parseInt(st.nextToken()); // 파티 수
		st = new StringTokenizer(br.readLine());
		int tc = Integer.parseInt(st.nextToken()); // 진실을 아는 사람 수
		int[] truthPeople = new int[tc];
		for (int i = 0; i < tc; i++) {
			truthPeople[i] = Integer.parseInt(st.nextToken());
		}
		HashSet<Integer>[] party = new HashSet[m + 1];
		for (int i = 0; i < m + 1; i++) {
			party[i] = new HashSet<>();
		}
		for (int i = 1; i < m + 1; i++) {
			st = new StringTokenizer(br.readLine());
			int pc = Integer.parseInt(st.nextToken()); // 파티에 가는 사람 수
			for (int j = 0; j < pc; j++) {
				party[i].add(Integer.parseInt(st.nextToken()));
			}
		}
		boolean[] visit = new boolean[m + 1];
		for (int i = 0; i < tc; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (!visit[j] && party[j].contains(truthPeople[i])) {
					Queue<Integer> q = new LinkedList<>();
					visit[j] = true;
					q.add(j);
					while (!q.isEmpty()) {
						int cur = q.poll();
						for (int x : party[cur]) {
							for (int y = 1; y < m + 1; y++) {
								if (!visit[y] && party[y].contains(x)) {
									visit[y] = true;
									q.add(y);
								}
							}
						}
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i < m + 1; i++) {
			if (!visit[i]) cnt++;
		}
		System.out.println(cnt);
	}
}
