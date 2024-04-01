import java.util.*;
import java.io.*;

public class Hoseok21276 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		HashMap<String, Integer> indegreeCnt = new HashMap<>();
		Map<String, List<String>> gragh = new TreeMap<>();
		st = new StringTokenizer(br.readLine());
		for  (int i = 0; i < n; i++) {
			String name = st.nextToken();
			indegreeCnt.put(name, 0);
			gragh.put(name, new ArrayList<String>());
		}
		int m = Integer.parseInt(br.readLine());
		List<List<String>> tmp = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			String descendant = st.nextToken();
			String ancester = st.nextToken();
			List<String> tmpList = new ArrayList<>();
			tmpList.add(descendant);
			tmpList.add(ancester);
			tmp.add(tmpList);
			indegreeCnt.put(descendant, indegreeCnt.get(descendant) + 1);
			gragh.get(ancester).add(descendant);
		}
		for (int idx = 0; idx < m; idx++) {
			for (String name : gragh.keySet()) {
				//System.out.println(name + gragh.get(name) + " " + tmp.get(idx).get(0) + " " + tmp.get(idx).get(1));
				if (gragh.get(name).contains(tmp.get(idx).get(0)) && gragh.get(name).contains(tmp.get(idx).get(1))) {
					gragh.get(name).remove(tmp.get(idx).get(0));
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (String key : indegreeCnt.keySet()) {
			if (indegreeCnt.get(key) == 0) {
				sb.append(key).append(' ');
			}
		}
		sb.append('\n');
		for (String key : gragh.keySet()) {
			sb.append(key).append(' ').append(gragh.get(key).size()).append(' ');
			Collections.sort(gragh.get(key));
			for (int i = 0; i < gragh.get(key).size(); i++) {
				sb.append(gragh.get(key).get(i)).append(' ');
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}
