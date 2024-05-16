import java.util.*;

class Solution {
	public int solution(int[] order) {
		int answer = 0;
		Stack<Integer> stack = new Stack<>();
		Queue<Integer> queue = new LinkedList<>();
		
		for(int i = 1; i <= order.length; i++) {
			queue.add(i);
		}
		
		int i = 0;
		
		while(true) {
			boolean flag = false;
			if (!queue.isEmpty() && order[i] == queue.peek()) {
				queue.poll();
				answer++;
				i++;
				flag = true;
				continue;
			}
			if (!stack.isEmpty() && order[i] == stack.peek()) {
				stack.pop();
				answer++;
				i++;
				flag = true;
				continue;
			}
			if (!queue.isEmpty()) {
				stack.add(queue.poll());
				flag = true;
			}
			if (!flag) {
				break;
			}
		}
		return answer;
	}
}