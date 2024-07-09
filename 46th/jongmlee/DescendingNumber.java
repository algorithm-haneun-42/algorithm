import java.io.*;
import java.util.*;

public class DescendingNumber {
	static String[] nums = {"00", "010", "0210", "03210", "043210", "054321", "06543210", "076543210", "08765423210"};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if (n < 10) {
			System.out.println(n);
			return;
		}
		int[] arr = new int[10];
		for (int i = 1; i < 10; i++) arr[i] = i;
		int sum = 9;
		for (int i = 2; i < 11; i++) {
			for (int j = 1; j < 10; j++) {
				sum += arr[j];
				if (sum <= n) {
					int startIdx  = sum - arr[j] + 1;
					// i 자리의 j - 1 로 시작하는 가장 작은 감소하는 수
					StringBuilder sb = new StringBuilder(nums[i - 2]);
					System.out.println((char)(j - 1 + '0'));
					sb.setCharAt(0, (char)(j - 1));
					int startNum = Integer.parseInt(sb.toString());
					int l = String.valueOf(startNum).length();
					while (String.valueOf(startNum).length() == l) {
						startNum++;
						if (!isDescending(startNum)) continue;
						startIdx++;
						if (startIdx == n) {
							System.out.println(startNum);
							return;
						}
					}
				}
			}
			rearrange(arr);
		}
		System.out.println("-1");
	}
	static void rearrange(int[] arr) {
		for (int i = 1; i < 11; i++) {
			arr[i] = arr[i - 1] + arr[i];
		}
	}
	static boolean isDescending(int num) {
		char[] arr = String.valueOf(num).toCharArray();
		for (int i = 0; i < arr.length - 1; i++) {
			if (arr[i] <= arr[i + 1]) {
				return false;
			}
		}
		return true;
	}
}
