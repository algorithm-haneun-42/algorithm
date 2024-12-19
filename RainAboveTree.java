import java.io.*;
import java.util.*;

public class RainAboveTree {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		List<List<Integer>> list = new ArrayList<>();
		for (int i = 0; i <= n; i++) list.add(new ArrayList<>());
		for (int i = 0; i < n - 1; i ++) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			list.get(from).add(to);
			list.get(to).add(from);
		}
		int leafCnt = 0;
		for (int i = 2; i <= n; i++) {
			if (list.get(i).size() == 1) {
				leafCnt++;
			}
		}
		System.out.println(String.format("%.10f", (double)w / leafCnt));
	}
}