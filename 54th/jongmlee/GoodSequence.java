import java.io.*;
import java.util.*;

public class GoodSequence {
	static int n;
	static int[] arr;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n];
		recul(0, 0);
	}
	static void recul(int depth, int pre) {
		if (depth == n) {
			for (int i = 0; i < n; i++) {
				System.out.print(arr[i]);
			}
			System.exit(0);
		}
		for (int i = 1; i <= 3; i++) {
			if (i != pre) {
				arr[depth] = i;
				if (isGood(depth)) {
					recul(depth + 1, i);
				}
				arr[depth] = 0;
			}
		}
	}
	static boolean isGood(int idx) {
		List<Integer> list = new ArrayList<>();
		for (int i = idx - 1; i >= idx / 2; i--) {
			if (arr[i] == arr[idx]) {
				list.add(i);
			}
		}
		loop:
		for (int x : list) {
			int lo = x;
			int hi = idx;
			while (hi > x) {
				if (arr[lo] != arr[hi]) {
					continue loop;
				}
				hi--;
				lo--;
			}
			return false;
		}
		return true;
	}
}
