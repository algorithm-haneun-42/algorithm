import java.io.*;
import java.util.*;

public class ListOfUniqueNubers {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		boolean[] v = new boolean[100001];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		long answer = 0;
		int j = 0;
		for (int i = 0; i < n; i++) {
			for (; j < n; j++) {
				if (v[arr[j]]) {
					break;
				}
				v[arr[j]] = true;
			}
			answer += j - i;
			v[arr[i]] = false;
		}
		System.out.println(answer);
	}
}
