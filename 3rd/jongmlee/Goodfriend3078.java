import java.io.*;
import java.util.*;

public class Goodfriend3078 {
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[] friends = new int[n];
		int[] nameLen = new int[21];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			friends[i] = st.nextToken().length();
		}
		for (int i = 0; i <= k && i < n; i++) {
			nameLen[friends[i]]++;
		}
		long answer = 0;
		int start = 0;
		int end = k;
		while (start < n - 1) {
			if (nameLen[friends[start]] > 1)
				answer += nameLen[friends[start]] - 1;
			nameLen[friends[start]]--;
			start += 1;
			if (end + 1 < n) {
				end += 1;
				nameLen[friends[end]]++;
			}
		}
		System.out.println(answer);
	}
}
