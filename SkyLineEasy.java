import java.io.*;
import java.util.*;

class SkyLineEasy {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st;
		int[] arr = new int[n + 1];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			st.nextToken();
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Stack<Integer> stack = new Stack<>();
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			while (!stack.isEmpty() && stack.peek() > arr[i]) {
				cnt++;
				stack.pop();
			}

			if (!stack.isEmpty() && stack.peek() == arr[i]) {
				continue;
			}

			stack.push(arr[i]);
		}

		System.out.println(cnt);
	}
}