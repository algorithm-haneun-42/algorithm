import java.io.*;
import java.util.*;

public class NewEmploy {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			int n = Integer.parseInt(br.readLine());
			int[] arr = new int[n + 1];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				arr[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
			}
			int cnt = 1;
			int vot = arr[1];
			for (int i = 2; i <= n; i++) {
				if (arr[i] < vot) {
					vot = arr[i];
					cnt++;
				}
			}
			System.out.println(cnt);
		}
	}
}
