import java.util.*;
import java.io.*;

public class DragonAndDungeon {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long attack = Long.parseLong(st.nextToken());

		long[][] room = new long[n][3];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				room[i][j] = Long.parseLong(st.nextToken());
			}
		}

		long maxHp = 0;
		long curHp = 0;
		long ma, mh;

		for (int i = 0; i < n; i++) {
			ma = room[i][1];
			mh = room[i][2];
			if (room[i][0] == 1) {
				curHp += ma * ((mh / attack) - (mh % attack != 0 ? 0 : 1));
				maxHp = Math.max(curHp, maxHp);
			} else {
				attack += ma;
				curHp = Math.max(curHp - mh, 0);
			}
		}

		System.out.println(++maxHp);

	}
}
