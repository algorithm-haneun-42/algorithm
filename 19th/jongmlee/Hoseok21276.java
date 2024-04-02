import java.util.*;
import java.io.*;

public class Hoseok21276 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		Map<String, Integer> indegreeCnt = new TreeMap<>();
		Map<String, List<String>> graph = new TreeMap<>();
		st = new StringTokenizer(br.readLine());
		for  (int i = 0; i < n; i++) {
			String name = st.nextToken();
			indegreeCnt.put(name, 0);
			graph.put(name, new ArrayList<String>());
		}
		int m = Integer.parseInt(br.readLine());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			String descendant = st.nextToken();
			String ancester = st.nextToken();
			indegreeCnt.put(descendant, indegreeCnt.get(descendant) + 1);
			graph.get(ancester).add(descendant);
		}
		
		Map<String, PriorityQueue<String>> children = new TreeMap<>();
		ArrayList<String> roots = new ArrayList<>();
		Queue<String> q = new LinkedList<>();
		StringBuilder sb = new StringBuilder();
		for (String key : indegreeCnt.keySet()) {
			children.put(key, new PriorityQueue<>());
			if (indegreeCnt.get(key) == 0) {
				q.add(key);
				roots.add(key);
			}
		}
		sb.append(roots.size()).append('\n');
		for (String root : roots) {
			sb.append(root).append(' ');
		}
		sb.append('\n');
		while(!q.isEmpty()) {
			String cur = q.poll();
			List<String> curList = graph.get(cur);
			for (int i = 0; i < curList.size(); i++) {
				indegreeCnt.put(curList.get(i), indegreeCnt.get(curList.get(i)) - 1);
				if (indegreeCnt.get(curList.get(i)) == 0) {
					children.get(cur).add(curList.get(i));
					q.add(curList.get(i));
				}
			}
		}

		for (String key : children.keySet()) {
			sb.append(key).append(' ').append(children.get(key).size());
			for (String child : children.get(key)) {
				sb.append(' ').append(child);
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}
