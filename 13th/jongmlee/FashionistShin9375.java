import java.io.*;
import java.util.*;

class FashionistShin9375 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer st;
		HashMap<String, Integer> map = new HashMap<>();
		while (t-- > 0) {
			map.clear();
			int n = Integer.parseInt(br.readLine());
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				st.nextToken();
				String key = st.nextToken();
				map.put(key, map.getOrDefault(key, 1) + 1);
			}
			long sum = 1;
			for (Map.Entry<String,Integer> entry : map.entrySet()) {
				sum *= entry.getValue();
			}
			System.out.println(sum - 1);
		}
	}
}