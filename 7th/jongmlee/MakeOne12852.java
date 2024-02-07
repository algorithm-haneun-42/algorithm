import java.util.*;

public class MakeOne12852 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n == 2) {
			System.out.println(1);
			System.out.println(2 + " " + 1);
			return ;
		}
		if (n == 1) {
			System.out.println(0);
			System.out.println(1);
			return ;
		}
		int[] dp = new int[n + 1];
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i < n + 1; i++) {
			int n1 = dp[i - 1];
			int n2 = Integer.MAX_VALUE;
			int n3 = Integer.MAX_VALUE;
			if (i % 2 == 0) {
				n2 = dp[i / 2];
			}
			if (i % 3 == 0) {
				n3 = dp[i / 3];
			}
			dp[i] = Math.min(Math.min(n1, n2), n3) + 1;
		}
		System.out.println(dp[n]);
		while (n > 1) {
			System.out.print(n + " ");
			int v;
			int n1 = dp[n - 1];
			int n2 = Integer.MAX_VALUE;
			int n3 = Integer.MAX_VALUE;
			if (n % 2 == 0) {
				n2 = dp[n / 2];
			}
			if (n % 3 == 0) {
				n3 = dp[n / 3];
			}
			v = Math.min(Math.min(n1, n2), n3);
			if (dp[n - 1] == v) {
				n = n - 1;
			} else if (n2 != Integer.MAX_VALUE && dp[n / 2] == v) {
				n = n / 2;
			} else if (n3 != Integer.MAX_VALUE && dp[n / 3] == v) {
				n = n / 3;
			}
		}
		System.out.println(n);
	}
}
