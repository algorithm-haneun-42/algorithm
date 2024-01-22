import java.util.*;

public class Coin11047 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(), target = sc.nextInt();
		
		int[] coins = new int[n];
		for (int i = 0; i < n; i++) {
			coins[i] = sc.nextInt();
		}

		int cnt = 0;
		for (int i = n - 1; i >= 0 && target > 0; i--) {
			if (coins[i] <= target) {
				cnt += target / coins[i];
				target -= target / coins[i] * coins[i];
			}
		}
		System.out.println(cnt);
	}
}
