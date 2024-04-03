import java.io.*;
import java.util.*;


public class SanguenJourney9372 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(br.readLine());
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			for (int i = 0; i < m; i++) {
				br.readLine();
			}
			System.out.println(n - 1);
		}
	}
}
