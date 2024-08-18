import java.io.*;
import java.util.*;

public class DanceParty {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> mm = new PriorityQueue<>();
		PriorityQueue<Integer> pm = new PriorityQueue<>(Comparator.reverseOrder());
		PriorityQueue<Integer> mf = new PriorityQueue<>();
		PriorityQueue<Integer> pf = new PriorityQueue<>(Comparator.reverseOrder());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int male = Integer.parseInt(st.nextToken());
			if (male < 0) {
				mm.add(male);
			} else {
				pm.add(male);
			}
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			int female = Integer.parseInt(st.nextToken());
			if (female < 0) {
				mf.add(female);
			} else {
				pf.add(female);
			}
		}
		int sum = 0;
		while (!mm.isEmpty() && !pf.isEmpty()) {
			if (Math.abs(mm.peek()) <= pf.peek()) {
				pf.poll();
			} else {
				mm.poll();
				pf.poll();
				sum++;
			}
		}
		while (!pm.isEmpty() && !mf.isEmpty()) {
			if (Math.abs(mf.peek()) <= pm.peek()) {
				pm.poll();
			} else {
				pm.poll();
				mf.poll();
				sum++;
			}
		}
		System.out.println(sum);
	}
}
