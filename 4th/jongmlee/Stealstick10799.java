import java.io.*;
import java.util.*;

public class Stealstick10799 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();

		Stack<Character> stack = new Stack<>();
		int stickCnt = 0;
		int answer = 0;
		for (int i = 0; i < line.length(); i++) {
			char tmp = line.charAt(i);
			if (tmp == '(') {
				stack.push(tmp);
				stickCnt++;
			} else if (tmp == ')') {
				if (stack.peek() == '(') {
					stack.push(tmp);
					stickCnt--;
					answer += stickCnt;
				} else {
					stack.push(tmp);
					answer += 1;
					stickCnt--;
				}
			}
		}
		System.out.println(answer);
	}
}
