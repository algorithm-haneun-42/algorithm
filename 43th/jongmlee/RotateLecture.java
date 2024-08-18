import java.io.*;
import java.util.*;

public class RotateLecture {
	static class Node {
		int p;
		int d;
		public Node(int p, int d) {
			this.p = p;
			this.d = d;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		Node[] arr = new Node[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int pay = Integer.parseInt(st.nextToken());
			int day = Integer.parseInt(st.nextToken());
			arr[i] = new Node(pay, day);
		}
		Arrays.sort(arr, (o1, o2) -> {
			if (o1.p == o2.p) {
				return o2.d - o1.d;
			}
			return o2.p - o1.p;
		});
		long answer = 0;
		boolean[] days = new boolean[10001];
		for (int i = 0; i < n; i++) {
			for (int j = arr[i].d; j >= 1; j--) {
				if (!days[j]) {
					days[j] = true;
					answer += arr[i].p;
					break;
				}
			}
		}
		System.out.println(answer);
	}
}
