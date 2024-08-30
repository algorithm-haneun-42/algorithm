import java.io.*;
import java.util.*;

public class CompanyCulture {
	static int[] cnts;
	static List<List<Integer>> parents;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		cnts = new int[n + 1];
		parents = new ArrayList<List<Integer>>();
		for (int i = 0; i < n + 1; i++) parents.add(new ArrayList<Integer>());
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			int tmp = Integer.parseInt(st.nextToken());
			if (i > 1) {
				parents.get(tmp).add(i);
			}
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			cnts[k] += w;
			//System.out.println(Arrays.toString(cnts));
		}
		praise(1);
		StringBuilder sb = new StringBuilder();
		sb.append("0 "); 
		for (int i = 2; i <= n; i++) {
			sb.append(cnts[i]).append(' ');
		}
		System.out.println(sb);
	}
	static void praise(int idx) {
		for (int i = 0; i < parents.get(idx).size(); i++) {
			cnts[parents.get(idx).get(i)] += cnts[idx];
			praise(parents.get(idx).get(i));
		}
	}
}
