import java.util.*;
import java.io.*;

public class InsertOperator14888 {
    public static int max = Integer.MIN_VALUE;
    public static int min = Integer.MAX_VALUE;
    public static int n;
    public static int[] operatorArr;
    public static int[] arr;
    public static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
		st = new StringTokenizer(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int num = Integer.parseInt(st.nextToken());
            for (int j = 0; j < num; j++) {
                list.add(i);
            }
        }

        operatorArr = list.stream().mapToInt(o -> o).toArray();
        visit = new boolean[operatorArr.length];

        recursion(1 , arr[0]);
        visit[0] = true;

        System.out.println(max);
        System.out.println(min);

    }

    private static void recursion(int depth ,int result) {
        if (depth == n) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }

        for (int i = 0; i < operatorArr.length; i++) {
            if (!visit[i]) {
                visit[i] = true;
                int tempResult = carculate(result, operatorArr[i], arr[depth]);
                recursion(depth + 1, tempResult);
                visit[i] = false;
            }
        }
    }

    private static int carculate(int result, int operator, int num) {
        if (operator == 0) {
            result += num;
        } else if (operator == 1) {
            result -= num;
        } else if (operator == 2) {
            result *= num;
        } else {
            result *= -1;
            result /= num;
            result *= -1;
        }


        return result;
    }
}
