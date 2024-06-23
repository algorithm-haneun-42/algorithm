import java.io.*;
import java.util.*;

public class Robot {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] endure = new int[n * 2];
		boolean[] robot = new boolean[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < endure.length; i++) {
			endure[i] = Integer.parseInt(st.nextToken());
		}
		int level = 0;
		while (true) {
			level++;
			// 1단계
			int tmp = endure[2 * n - 1];
			for (int i = 2 * n - 1; i > 0; i--) {
				endure[i] = endure[i - 1];
			}
			endure[0] = tmp;
			for (int i = n - 1; i > 0; i--) {
				robot[i] = robot[i - 1];
			}
			robot[0] = false;
			robot[n - 1] = false;
			// 2단계
			for (int i = n - 1; i > 0; i--) {
				if (robot[i - 1] && !robot[i] && endure[i] > 0) {
					endure[i]--;
					robot[i] = true;
					robot[i - 1] = false;
				}
			}
			robot[n - 1] = false;
			// 3단계
			if (endure[0] > 0) {
				robot[0] = true;
				endure[0]--;
			}
			int cnt = 0;
			for (int i = 0; i < endure.length; i++) {
				if (endure[i] == 0) cnt++;
			}
			if (cnt >= k) {
				System.out.println(level);
				return;
			}
		}
	}
}
