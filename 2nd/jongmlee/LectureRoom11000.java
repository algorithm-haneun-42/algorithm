import java.util.*;

class LectureRoom11000 {
	static class Lecture {
		int start;
		int end;

		Lecture(int start, int end) {
			this.start = start;
			this.end = end;
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		Lecture[] lectures = new Lecture[n];
		for (int i = 0; i < n; i++) {
			lectures[i] = new Lecture(sc.nextInt(), sc.nextInt());
		}
		Arrays.sort(lectures, (x1, x2) -> x1.start == x2.start ? x1.end - x2.end : x1.start - x2.start);
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.offer(lectures[0].end);
		for (int i = 1; i < n; i++) {
			if (pq.peek() <= lectures[i].start) {
				pq.poll();
			}
			pq.offer(lectures[i].end);
		}
		System.out.println(pq.size());
	}
}