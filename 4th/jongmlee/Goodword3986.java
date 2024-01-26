import java.io.*;
import java.util.*;

public class Goodword3986 {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		Stack<Character> stack = new Stack<>();
		int answer = 0;
		for (int i = 0; i < n; i++) {
			stack.clear();
			String line = br.readLine();
			for (int j = 0; j < line.length(); j++) {
				char tmp = line.charAt(j);
				if (tmp == 'A') {
					if (!stack.empty() && stack.peek() == 'A') {
						stack.pop();
					} else {
						stack.push(tmp);
					}
				} else if (tmp == 'B') {
					if (!stack.empty() && stack.peek() == 'B') {
						stack.pop();
					} else {
						stack.push(tmp);
					}
				}
			}
			if (stack.isEmpty()) {
				answer++;
			}
		}
		System.out.println(answer);
	}
}
