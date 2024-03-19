import java.io.*;
import java.util.*;

public class JewelThief1202 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		ArrayList<Gem> gems = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			gems.add(new Gem(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		int[] bags = new int[k];
		for (int i = 0; i < k; i++) {
			bags[i] = Integer.parseInt(br.readLine());
		}
		gems.sort((x, y) -> x.weight - y.weight);
		Arrays.sort(bags);
		PriorityQueue<Gem> pq = new PriorityQueue<>((x, y) -> y.value - x.value);
		long answer = 0;
		int idx = 0;
		for (int i = 0; i < k; i++) {
			while (idx < n && gems.get(idx).weight <= bags[i]) {
				Gem cur = gems.get(idx++);
				pq.add(new Gem(cur.weight, cur.value));
			}
			if (!pq.isEmpty()) {
				answer += pq.poll().value;
			}
		}
		System.out.println(answer);
	}
	static class Gem{
		int weight;
		int value;
		public Gem(int weight, int value) {
			this.weight = weight;
			this.value = value;
		}
	}
}
