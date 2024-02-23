import java.io.*;
import java.util.*;

public class Truck13335 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); // 트럭 개수
		int w = Integer.parseInt(st.nextToken()); // 다리의 길이
		int l = Integer.parseInt(st.nextToken()); // 트럭 무게의 합
		Queue<Integer> bridge = new LinkedList<>();
		for (int i = 0; i < w; i++) { //다리길이만큼 큐에 0 넣어줌 
			bridge.add(0);
		}
		int totalWeight = 0;
		int time = 0;
		st = new StringTokenizer(br.readLine());
		int truck = Integer.parseInt(st.nextToken());
		while(true) {
			time++; 
			totalWeight -= bridge.poll();
			if(totalWeight + truck <= l) {
				bridge.add(truck);
				totalWeight += truck;
				if(--n == 0) break;
				truck = Integer.parseInt(st.nextToken());
			}else {
				bridge.add(0);
			}
		}
		time += bridge.size();
		System.out.println(time);
	}
}
