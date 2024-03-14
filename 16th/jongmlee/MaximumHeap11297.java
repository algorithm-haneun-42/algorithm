import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class MaximumHeap11297 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			int oper = Integer.parseInt(br.readLine());
			if (oper == 0) {
				if (pq.isEmpty()) {
					sb.append(0).append('\n');
				} else {
					sb.append(pq.poll()).append('\n');
				}
			} else {
				pq.add(oper);
			}
		}
		System.out.println(sb);
	}
}
