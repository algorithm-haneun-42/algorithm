import java.io.*;
import java.util.*;

public class RobotProject {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = "";
		while ((input = br.readLine()) != null) {
			int x = Integer.parseInt(input) * 10000000;
			int n = Integer.parseInt(br.readLine());
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(br.readLine());
			}
			Arrays.sort(arr);
			int lo = 0;
			int hi = n - 1;
			int a1 = 0;
			int a2 = 0;
			int max = 0;
			while (lo < hi) {
				if (arr[lo] + arr[hi] == x) {
					a1 = lo;
					a2 = hi;
					max = arr[lo] + arr[hi];
					break;
				} else if (arr[lo] + arr[hi] < x) {
					lo++;
				} else {
					hi--;
				}
			}
			if (max == 0) {
				System.out.println("danger");
			} else {
				System.out.println("yes " + arr[a1] + " " + arr[a2]);
			}
		}

	}
}
