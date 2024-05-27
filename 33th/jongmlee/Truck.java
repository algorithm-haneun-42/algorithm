import java.util.*;

class Solution {
	public int solution(int bridge_length, int weight, int[] truck_weights) {
		int time = 0;
		int sum = 0;
		Queue<Integer> q = new LinkedList<>();
		for (int tw : truck_weights) {
			while (true) {
				if (q.isEmpty()) {
					q.add(tw);
					sum += tw;
					time++;
					break;
				} else if (q.size() == bridge_length) {
					int truck = q.poll();
					sum -= truck;
					time++;
					if (tw + sum <= weight) {
						q.add(tw);
						sum += tw;
						break;
					} else {
						q.add(0);
					}
				} else {
					time++;
					if (tw + sum <= weight) {
						q.add(tw);
						sum += tw;
						break;
					} else {
						q.add(0);
					}
				}
			}
		}
		return time + bridge_length;
	}
}