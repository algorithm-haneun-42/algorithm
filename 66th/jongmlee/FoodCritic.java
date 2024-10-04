import java.io.*;
import java.util.StringTokenizer;

public class FoodCritic {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		System.out.println(m - GCD(n, m));
	}
	static int GCD(int a, int b) {
		if (b == 0) return a;
		return GCD(b, a % b);
	}
}
