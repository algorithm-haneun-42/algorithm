import java.util.*;

class RotateBracket {
    public int solution(String s) {
        int answer = 0;
        char[] arr = s.toCharArray();
        for (int i = 0; i < s.length(); i++) {
            if (isRight(arr, i)) answer++;
        }
        return answer;
    }
    static boolean isRight(char[] arr, int start) {
        int idx = 0;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < arr.length; i++) {
            idx = (start + i) % arr.length;
            char cur = arr[idx];
            int dir = toDir(cur);
            if (stack.isEmpty()) {
                if (dir % 2 == 1) {
                    return false;
                }
                stack.push(cur);
            } else {
                if (dir % 2 == 0) {
                    stack.push(cur);
                } else {
                    if (toDir(stack.pop()) != dir - 1) {
                        return false;
                    }
                }
            }
        }
        if (stack.isEmpty()) {
            return true;
        }
        return false;
    }
    static int toDir(char c) {
        if (c == '(') return 0;
        if (c == ')') return 1;
        if (c == '[') return 2;
        if (c == ']') return 3;
        if (c == '{') return 4;
        if (c == '}') return 5;
        return 0;
    }
}