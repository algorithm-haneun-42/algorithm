import java.io.*;
import java.util.*;

public class Z {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		System.out.println(recul(n, r, c));
	}
	public static int recul(int n, int r, int c) {
		if (n == 0) return 0;
		int half = (int)Math.pow(2, n - 1);
		if (r < half && c < half) return recul(n - 1, r, c);
		else if (r < half && c >= half) return (half * half) + recul(n - 1, r, c - half);
		else if (r >= half && c < half) return (half * half * 2) + recul(n - 1, r - half, c);
		else return (half * half * 3) + recul(n - 1, r - half, c - half);
	}
}
