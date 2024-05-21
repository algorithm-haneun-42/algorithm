import java.util.*;

class LifeBoat {
	public int solution(int[] people, int limit) {
		int answer = 0;
		Arrays.sort(people);
		int lo = 0;
		int hi = people.length - 1;
		while (hi > lo) {
			if (people[lo] + people[hi] <= limit) {
				people[lo] = 0;
				people[hi] = 0;
				answer++;
				lo++;
			}
			hi--;
		}
		for (int x : people) {
			if (x != 0) {
				answer++;
			}
		}
		return answer;
	}
}
