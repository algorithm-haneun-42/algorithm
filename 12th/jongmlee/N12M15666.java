import java.io.*;
import java.util.*;

public class N12M15666 {
	static int[] arr, nums;
	static int n, m;
	static StringBuilder sb = new StringBuilder();
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		nums = new int[n];
		arr = new int[m];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(nums);
		permutation(0, 0);
		System.out.println(sb);
	}
	static void permutation(int idx, int depth) {
		if (depth == m) {
			for (int i = 0; i < depth; i++) {
				sb.append(arr[i]).append(" ");
			}
			sb.append("\n");
			return;
		}
		int val = 0;
		for (int i = idx; i < n; i++) {
			if (val != nums[i]) {
				arr[depth] = nums[i];
				val = arr[depth];
				permutation(i, depth + 1);
			}
		}
	}
}
