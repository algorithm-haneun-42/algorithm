import java.util.*;

public class Hide13913 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		if (n == k) {
			System.out.println(0);
			System.out.println(n);
			return ;
		}
		int[] line = new int[100001];
		Arrays.fill(line, -1);
		int[] dir = {-1, 1, 2};
		Queue<Integer> q = new LinkedList<>();
		Stack<Integer> stack = new Stack<>();
		line[n] = -2;
		q.add(n);
		while(!q.isEmpty()) {
			int cur = q.poll();
			if (cur == k) {
				int tmp = k;
				while (tmp != n) {
					stack.push(tmp);
					tmp = line[tmp];
				}
				System.out.println(stack.size());
				System.out.print(n + " ");
				while (!stack.isEmpty()) {
					System.out.print(stack.pop() + " ");
				}
				break;
			}
			for (int i = 0; i < 3; i++) {
				int newP = cur + dir[i];
				if (i == 2) newP = cur * 2;
				if (newP >= 0 && newP <= 100000 && line[newP] == -1) {
					line[newP] = cur;
					q.add(newP);
				}
			}
		}
	}
}