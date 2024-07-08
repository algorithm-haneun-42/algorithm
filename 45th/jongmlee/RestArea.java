import java.io.*;
import java.util.*;

public class RestArea {
	static int n, m, l;
	static int[] dist;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		dist = new int[n + 2];
		dist[0] = 0; dist[n + 1] = l;
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < n + 1; i++) {
			dist[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(dist);
		for (int i = 0; i <= n; i++) {
			dist[i] = dist[i + 1] - dist[i] - 1;
		}
		int lo = 1, hi = l;
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			if(restCnt(mid) <= m) {
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}
		System.out.println(lo);
	}
	static int restCnt(int target) {
		int ret = 0;
		for (int i = 0 ; i <= n; i++) {
			ret += dist[i] / target;
		}
		return ret;
	}
}
