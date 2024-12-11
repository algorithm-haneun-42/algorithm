import java.io.*;
import java.util.*;

public class Cat {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		char[] arr = br.readLine().toCharArray();
		HashMap<Character, Integer> map = new HashMap<>();
		int max = Integer.MIN_VALUE;
		int s = 0;
		int e = 0;
		boolean isE = true;
		while (s <= e && e < arr.length) {
			char newC = isE ? arr[e] : arr[s];
			if (!map.containsKey(newC)) {
				map.put(newC, 1);
			} else if (isE) {
				map.put(newC, map.get(newC) + 1);
			}
			if (map.size() > n) {
				map.put(arr[s], map.get(arr[s]) - 1);
				if (map.get(arr[s]) == 0) {
					map.remove(arr[s]);
				}
				s++;
				isE = false;
				continue;
			}
			max = Math.max(e - s + 1, max);
			e++;
			isE = true;
		}
		System.out.println(max);
	}
}
