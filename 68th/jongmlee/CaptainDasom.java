import java.util.*;

public class CaptainDasom {
	static ArrayList<Integer> list = new ArrayList<Integer>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		
		int num = 1;
		int num1 = 1;
		for (int i = 2; num1 <= 300000; i++) {
			list.add(num1);
			num += i;
			num1 += num;
		}
		
		int[] dp = new int[300001];
		for (int i = 0; i < dp.length; i++)
			dp[i] = -1;

		dp[0] = 0;
		for (int i = 0; i < list.size(); i++) {
			for (int j = list.get(i); j < dp.length; j++) {
				if (dp[j] == -1) {
					dp[j] = dp[j - list.get(i)] + 1;
				} else {
					dp[j] = Math.min(dp[j], dp[j - list.get(i)] + 1);
				}
			}
		}
		System.out.println(dp[k]);
	}
}