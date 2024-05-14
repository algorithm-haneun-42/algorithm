import java.util.*;

class SaleEvent {
	static Map<String, Integer> map;
	
	public int solution(String[] want, int[] number, String[] discount) {
		int answer = 0;
		map = new HashMap<>();
		for (int i = 0; i < 10; i++) {
			map.put(discount[i], map.getOrDefault(discount[i], 0) + 1);
		}
		if (check(want, number)) answer++;
		for (int i = 1; i <= discount.length - 10; i++) {
			//0번째를 빼고 i - 1
			map.put(discount[i - 1], map.get(discount[i - 1]) - 1);
			//10번째를 넣는다 i + 9
			map.put(discount[i + 9], map.getOrDefault(discount[i + 9], 0) + 1);
			if (check(want, number)) answer++;
		}
		return answer;
	}
	static boolean check(String[] want, int[] number) {
		for (int i = 0; i < want.length; i++) {
			if (!map.containsKey(want[i])) {
				return false;
			}
			if (map.get(want[i]) != number[i]) {
				return false;
			}
		}
		return true;
	}
}