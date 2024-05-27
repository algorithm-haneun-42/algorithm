import java.util.*;

class ExpressionOfNumber {
    public int solution(int n) {
        int answer = 0;
        int[] arr = new int[n + 1];
        for (int i = 1; i < arr.length; i++) {
            arr[i] = arr[i - 1] + i;
        }
        //System.out.println(Arrays.toString(arr));
        for (int i = arr.length - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] - arr[j] == n) {
                    answer++;
                } else if (arr[i] - arr[j] > n) {
                    break;
                }
            }
        }
        return answer;
    }
}