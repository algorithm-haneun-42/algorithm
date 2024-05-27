import java.util.*;

class Solution {
	public String solution(String number, int k) {
		char[] result = new char[number.length() - k];
		Stack<Character> stack = new Stack<>();

		for (int i = 0; i < number.length(); i++) {
			char c = number.charAt(i);
			while (!stack.isEmpty() && stack.peek() < c && k > 0) {
				stack.pop();
				k--;
			}
			stack.push(c);
		}
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < result.length; i++) {
			sb.append(stack.get(i));
		}

		return sb.toString();
	}
}