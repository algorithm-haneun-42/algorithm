import java.io.*;
import java.util.*;

public class JumpGame {
	static class Node {
		int time;
		int dir;
		int idx;
		public Node(int time, int dir, int idx) {
			this.time = time;
			this.dir = dir;
			this.idx = idx;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		String map1 = br.readLine();
		String map2 = br.readLine();
		// 시간, 방향, 현재 위치
		boolean[] v1 = new boolean[n];
		boolean[] v2 = new boolean[n];
		for (int i = 0; i < n; i++) {
			v1[i] = map1.charAt(i) == '0' ? false : true;
			v2[i] = map2.charAt(i) == '0' ? false : true;
		}
		Queue<Node> q = new LinkedList<>();
		q.add(new Node(1, 0, 0));
		while (!q.isEmpty()) {
			Node cur = q.poll();
			boolean[] nv1 = v1.clone();
			boolean[] nv2 = v2.clone();
			for (int i = 0; i < cur.time; i++) {
				nv1[i] = false;
				nv2[i] = false;
			}
			for (int i = 0; i < 3; i++) {
				int nidx, ndir;
				ndir = cur.dir;
				if (i == 0) {
					nidx = cur.idx + 1;
				} else if (i == 1) {
					nidx = cur.idx - 1;
				} else {
					ndir = cur.dir == 1 ? 0 : 1;
					nidx = cur.idx + k;
				}
				if (nidx >= n) {
					System.out.println("1");
					return;
				}
				if (nidx < 0) continue;
				if ((ndir == 0 && nv1[nidx]) || (ndir == 1 && nv2[nidx])) {
					q.add(new Node(cur.time + 1, ndir, nidx));
				}
			}
		}
		System.out.println("0");
	}
}
