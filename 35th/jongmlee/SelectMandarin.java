import java.util.*;
class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int x : tangerine) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        List<Integer> list = new ArrayList<>(map.keySet());
        list.sort( (o1 , o2) -> map.get(o2) - map.get(o1));
        for (int x : list) {
            if (k <= 0) { 
                break;
            }
            answer++;
            k -= map.get(x);
        }
        return answer;
    }
}
