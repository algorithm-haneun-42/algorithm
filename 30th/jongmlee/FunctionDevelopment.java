import java.util.*;

class FunctionDevelopment {
	public int[] solution(int[] progresses, int[] speeds) {
		List<Integer> list = new ArrayList<>();
		int idx = 0;
		while (!check(progresses)) {
			for (int i = 0; i < speeds.length; i++) {
				if (progresses[i] == -1) continue;
				progresses[i] += speeds[i];
			}
			if (progresses[idx] >= 100) {
				int cnt = 0;
				progresses[idx++] = -1;
				cnt++;
				for (; idx < speeds.length; idx++) {
					if (progresses[idx] >= 100) {
						progresses[idx] = -1;
						cnt++;
					} else {
						break;
					}
				}
				list.add(cnt);
			}
		}
		int[] answer = new int[list.size()];
		for (int i = 0 ; i < answer.length; i++) {
			answer[i] = list.get(i);
		}
		return answer;
	}
	static boolean check(int[] progresses) {
		for (int x : progresses) {
			if (x != -1) {
				return false;
			}
		}
		return true;
	}
}