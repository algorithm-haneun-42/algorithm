import java.util.*;

class Mechanic1449 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int l = sc.nextInt();

		int[] arr = new int[1001];
		Arrays.fill(arr, 0);
		for (int i = 0; i < n; i++) {
			arr[sc.nextInt()] = 1;
		}
		int cnt = 0;
		for (int i = 1; i < 1001; i++) {
			if (arr[i] == 1) {
				cnt++;
				for (int j = 0; j < l && i + j < 1001; j++) {
					arr[i + j] = 0;
				}
			}
		}
		System.out.println(cnt);
    }
}