import java.io.*;
import java.util.*;

public class SumIsZero {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		int[] cnt = new int[40001];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		long answer = 0;
		for (int i = 0; i < n; i++) {
			answer += cnt[20000 - arr[i]];
			for (int j = 0; j < i; j++) {
				cnt[20000 + arr[i] + arr[j]]++;
			}
		}
		System.out.println(answer);
	}
}
