import java.util.*;

class Solution {
	public int MoreSpicy(int[] scoville, int K) {
		int answer = 0;
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int x : scoville) {
			pq.add(x);
		}
		while (pq.peek() < K && pq.size() >= 2) {
			pq.add(pq.poll() + (pq.poll() * 2));
			answer++;
		}
		if (pq.peek() < K) answer = -1;
		return answer;
	}
}