import java.io.*;
import java.util.*;

public class Firefly {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		int[] low = new int[h + 1];
		int[] hi = new int[h + 1];
		for (int i = 0; i < n; i += 2) {
			int n1 = Integer.parseInt(br.readLine());
			int n2 = Integer.parseInt(br.readLine());
			low[n1]++;
			hi[n2]++;
		}
		for (int i = h - 1; i > 0; i--) {
			low[i] += low[i + 1];
			hi[i] += hi[i + 1];
		}
		int obstacle = Integer.MAX_VALUE;
		int cnt = 0;
		for (int i = 1; i <= h; i++) {
			int tmp = low[i] + hi[h - i + 1];
			if (tmp < obstacle) {
				obstacle = tmp;
				cnt = 1;
			} else if (tmp == obstacle) {
				cnt++;
			}
		}
		System.out.println(obstacle + " " + cnt);
	}
}
