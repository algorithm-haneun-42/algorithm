import java.io.*;
import java.util.*;

public class FindPassword17219 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		HashMap<String, String> map = new HashMap<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			map.put(st.nextToken(), st.nextToken());
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m; i++) {
			sb.append(map.get(br.readLine())).append('\n');
		}
		System.out.println(sb);
	}
}
