import java.io.*;
import java.util.*;

public class World4949 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		Stack<Character> stack = new Stack<>();
		while (true) {
			stack.clear();
			int flag = 0;
			String line = br.readLine();
			if (line.equals(".")) break;
			for (int i = 0; i < line.length(); i++) {
				char tmp = line.charAt(i);
				if (tmp == '(') stack.push(tmp);
				else if (tmp == '[') stack.push(tmp);
				else if (tmp == ')') {
					if (stack.isEmpty() || stack.peek() != '(') {
						System.out.println("no");
						flag = 1;
						break ;
					}
					stack.pop();
				}
				else if (tmp == ']') {
					if (stack.isEmpty() || stack.peek() != '[') {
						System.out.println("no");
						flag = 1;
						break ;
					}
					stack.pop();
				}
			}
			if (stack.isEmpty() && flag == 0)
				System.out.println("yes");
			else if (flag == 0)
				System.out.println("no");
		}
	}
}
