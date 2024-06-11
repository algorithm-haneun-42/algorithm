import java.util.*;

class CuttingRollcake {
    public int solution(int[] topping) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int x : topping) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        for (int x : topping) {
            if (map.get(x) == 1) {
                map.remove(x);
            } else {
                map.put(x, map.get(x) - 1);
            }
            set.add(x);
            if (map.size() == set.size()) {
                answer++;
            }
         }
        return answer;
    }
}