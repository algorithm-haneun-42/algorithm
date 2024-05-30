import java.util.*;

class Hindex {
    public int solution(int[] citations) {
        int answer = 0;
        int max = Arrays.stream(citations).max().getAsInt();
        for (int i = max; i >= 0; i--) {
            int hi = 0;
            for (int x : citations) {
                if (x >= i) {
                    hi++;
                }
            }
            if (hi >= i) return i;
        }
        return answer;
    }
}