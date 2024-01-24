import java.io.*;
import java.util.*;


public class Card2164 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		Deque<Integer> deque = new LinkedList<>();
		for (int i = 1; i <= n; i++) {
			deque.addLast(i);
		}
		while (deque.size() > 1) {
			deque.pollFirst();
			deque.addLast(deque.pollFirst());
		}
		System.out.println(deque.pop());
	}
}
