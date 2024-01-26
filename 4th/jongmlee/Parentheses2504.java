import java.io.*;
import java.util.*;

public class Parentheses2504 {
	static class Data {
		char word;
		int operator; // 0 == +, 1 == *
		int value;
		Data(char word, int operator, int value) {
			this.word = word;
			this.operator = operator;
			this.value = value;
		}
	}
	public static void main(String[] args) throws IOException {
		System.out.println(solve());
	}

	static int solve() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		Stack<Data> stack = new Stack<>();
		int answer = 0;
		for (int i = 0; i < line.length(); i++) {
			char word = line.charAt(i);
			Data cur = new Data(word, 0, 0);
			if (word == '(' || word == '[') {
				stack.push(cur);
			} else { // 닫는 녀석인데
				// 스택이 비어있거나, 맨 위 요소가 종류가 다르면 fail
				if (stack.isEmpty() || !compare(stack.peek().word, word)) {
					return 0;
				}
				// 스택이 비어있지 않고, 맨 위 요소가 종류가 같다면	
				// 맨 위 요소의 operator와 value를 보고 값과 연산
				int tmp = cal(stack.peek().operator, stack.pop().value, getParenthesisValue(word));
				// 스택이 비어있으면 answer 에 해당 값을 더해줌
				if (stack.isEmpty()) {
					answer += tmp;
				} else {
					if (i + 1 >= line.length()) {
						return 0;
					}
					// 스택이 비어있지 않으면 맨 위 요소의 operator와 value를 보고 해당 값과 연산
					Data top = stack.peek();
					tmp = cal(top.operator, top.value, tmp);
					// 다음 문자가 닫는 문자라면 그 전 요소의 operator를 1로 바꾸고 방금 연산한 값 대입
					if (line.charAt(i + 1) == ')' || line.charAt(i + 1) == ']') {
						top.operator = 1;
						top.value = tmp;
					} else {
						// 다음 문자가 여는 문자라면 그 전 요소의 operator를 0으로 바꾸고 방금 연산한 값 대입
						top.operator = 0;
						top.value = tmp;
					}
				}
			}
		}
		return answer;
	}
	static int cal(int operator, int v1, int v2) {
		if (operator == 0)
			return v1 + v2;
		return v1 * v2;
	}
	static int getParenthesisValue(char tmp) {
		if (tmp == '(' || tmp == ')') {
			return 2;
		}
		return 3;
	}

	static Boolean compare(char open, char close) {
		if ((open == '(' && close == ')') || (open == '[' && close == ']'))
			return true;
		return false;
	}
}
