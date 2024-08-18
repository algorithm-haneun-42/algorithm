import java.io.*;
import java.util.*;

public class Diet {
	static int n, sum, min;
	static int[] limit, arr;
	static boolean[] v;
	static Food[] foods;
	static List<Integer> answer = new ArrayList<>();
	static List<Integer> cur = new ArrayList<>();
	static class Food {
		int mp;
		int mf;
		int ms;
		int mv;
		int cost;
		public Food(int mp, int mf, int ms, int mv, int cost) {
			this.mp = mp;
			this.mf = mf;
			this.ms = ms;
			this.mv = mv;
			this.cost = cost;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		limit = new int[4];
		for (int i = 0; i < 4; i++) {
			limit[i] = Integer.parseInt(st.nextToken());
		}
		foods = new Food[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int mp = Integer.parseInt(st.nextToken());
			int mf = Integer.parseInt(st.nextToken());
			int ms = Integer.parseInt(st.nextToken());
			int mv = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			foods[i] = new Food(mp, mf, ms, mv, cost);
		}
		sum = 0;
		min = Integer.MAX_VALUE;
		v = new boolean[n];
		recul(0);
		if (min == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(min);
			answer.forEach(x -> System.out.print((x + 1) + " "));
		}
	}
	public static void recul(int depth) {
		if (depth == n) {
			return;
		}
		if (isOver()) {
			if (sum < min) {
				min = sum;
				answer.clear();
				for (int i = 0; i < cur.size(); i++) {
					answer.add(cur.get(i));
				}
			}
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!v[i]) {
				v[i] = true;
				sum += foods[i].cost;
				cur.add(i);
				Integer value = i;
				recul(depth + 1);
				cur.remove(value);
				sum -= foods[i].cost;
				v[i] = false;
			}
		}
	}
	static boolean isOver() {
		arr = new int[4];
		for (int i = 0; i < cur.size(); i++) {
			arr[0] += foods[cur.get(i)].mp;
			arr[1] += foods[cur.get(i)].mf;
			arr[2] += foods[cur.get(i)].ms;
			arr[3] += foods[cur.get(i)].mv;
		}
		//System.out.println(Arrays.toString(arr));
		for (int i = 0; i < 4; i++) {
			if (arr[i] < limit[i]) {
				return false;
			}
		}
		return true;
	}
}
