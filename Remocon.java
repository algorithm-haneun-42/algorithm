import java.util.*;
import java.io.*;

public class Remocon {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int target = Integer.parseInt(br.readLine());
		int brokenCount = Integer.parseInt(br.readLine());
		
		boolean[] broken = new boolean[10];
		if (brokenCount > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < brokenCount; i++) {
				broken[Integer.parseInt(st.nextToken())] = true;
			}
		}
		int minPresses = Math.abs(target - 100);
		
		for (int channel = 0; channel <= 999999; channel++) {
			String strChannel = String.valueOf(channel);
			
			boolean isValid = true;
			for (char c : strChannel.toCharArray()) {
				if (broken[c - '0']) {
					isValid = false;
					break;
				}
			}
			
			if (isValid) {
				int presses = strChannel.length() + Math.abs(channel - target);
				minPresses = Math.min(minPresses, presses);
			}
		}
		
		System.out.println(minPresses);
	}
}
