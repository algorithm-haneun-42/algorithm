import java.io.*;
import java.util.*;

public class GroupTask {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int mx = 0;
		int my = Integer.MAX_VALUE;
		for (int i = 1; i < n; i += 2) {
			mx += arr[i] - arr[i - 1];
			my = Math.min(mx, my) + (arr[i + 1] - arr[i]);
		}
		System.out.println(my);
	}
}
