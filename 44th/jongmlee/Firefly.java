import java.io.*;
import java.util.*;

public class Firefly {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		int[] arr = new int[h + 1];
		arr[0] = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			int tmp = Integer.parseInt(br.readLine());
			if (i % 2 == 0) {
				for (int j = 1; j <= tmp; j++) {
					arr[j]++;
				}
			} else {
				for (int j = h; j > h - tmp; j--) {
					arr[j]++;
				}
			}
		}
		int min = Arrays.stream(arr).min().getAsInt();
		int cnt = 0;
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] == min) cnt++;
		}
		System.out.println(min + " " + cnt);
	}
}
