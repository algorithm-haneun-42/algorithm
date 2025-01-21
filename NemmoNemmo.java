import java.io.*;
import java.util.*;

public class NemmoNemmo {
	static int[][] map;
	static int answer, n , m;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		map = new int[n + 1][m + 1];
		answer = 0;
		dfs(0);
		System.out.println(answer);
	}

	static void dfs(int cnt) {
		if (cnt == n * m) {
			answer++;
			return;
		}

		int x = (cnt / m) + 1;
		int y = (cnt % m) + 1;

		if (map[x - 1][y] == 1 && map[x][y - 1] == 1 && map[x - 1][y - 1] == 1) {
			dfs(cnt + 1);
		} else {
			dfs(cnt + 1);
			map[x][y] = 1;
			dfs(cnt + 1);
			map[x][y] = 0;
		}
	}
}
