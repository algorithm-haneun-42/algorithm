import java.io.*;
import java.util.*;

public class Printerqueue1966 {
	static class Data {
		int num;
		int priority;
		Data(int num, int priority) {
			this.num = num;
			this.priority = priority;
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		Queue<Data> q = new LinkedList<>();
		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		for (int i = 0; i < n; i++) {
			pq.clear();
			q.clear();
			int answer = 0;
			st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			int target = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < cnt; j++) {
				int priority = Integer.parseInt(st.nextToken());
				q.add(new Data(j, priority));
				pq.add(priority);
			}
			Data tmp;
			while (true) {
				if (q.peek().priority < pq.peek()) {
					tmp = q.poll();
					q.add(tmp);
				} else {
					tmp = q.poll();
					pq.poll();
					answer++;
					if (tmp.num == target) break;
				}
			}
			System.out.println(answer);
		}
	}
}
