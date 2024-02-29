import java.io.*;
import java.util.*;

public class NQueen9663 {
	static int[] board;
	static int n, cnt;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		board = new int[n];
		reculsion(0);
		System.out.println(cnt);
	}
	static void reculsion(int depth) {
		if (depth == n) {
			cnt++;
			return ;
		}
		for (int i = 0; i < n; i++) {
			board[depth] = i;
			if (check(depth)) {
				reculsion(depth + 1);
			}
		}
	}
	static boolean check(int idx) {
		for (int i = 0; i < idx; i++) {
			if (board[idx] == board[i]) {
				return false;
			}
			if (Math.abs(idx - i) == Math.abs(board[idx] - board[i])) {
				return false;
			}
		}
		return true;
	}
}
