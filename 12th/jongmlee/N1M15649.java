import java.io.*;
import java.util.*;

public class N1M15649 {
	static int[] arr;
	static boolean[] v;
	static int n, m;
	static StringBuilder sb = new StringBuilder();
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[m];
		v = new boolean[n + 1];
		permutation(0);
		System.out.println(sb);
	}
	static void permutation(int depth) {
		if (depth == m) {
			for (int i = 0; i < depth; i++) {
				sb.append(arr[i]).append(" ");
			}
			sb.append("\n");
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				arr[depth] = i;
				v[i] = true;
				permutation(depth + 1);
				v[i] = false;
			}
		}
	}
}
