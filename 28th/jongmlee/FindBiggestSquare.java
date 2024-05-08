class Solution {
	public int FindBiggestSquare(int [][]board) {
		int answer = 0;
		int[][] dp = new int[board.length + 1][board[0].length + 1];
		for (int i = 1; i < board.length + 1; i ++) {
			for (int j = 1; j < board[0].length + 1; j++) {
				if (board[i - 1][j - 1] == 1) {
					dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
					answer = Math.max(dp[i][j], answer);
				}
			}
		}
		return answer * answer;
	}
}
