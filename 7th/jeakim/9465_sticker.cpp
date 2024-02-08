#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void set_score(int sticker[2][100000], int board[2][100000], int n)
{
	long score = 0;

	board[0][0] = sticker[0][0];
	board[1][0] = sticker[1][0];
	board[0][1] = sticker[0][1] + board[1][0];
	board[1][1] = sticker[1][1] + board[0][0];
	for (int i = 2; i < n; i++){
		board[0][i] = max(board[0][i - 2], board[1][i - 2] > board[1][i - 1] ? board[1][i - 2] : board[1][i - 1]) + sticker[0][i];
		board[1][i] = max(board[1][i - 2], board[0][i - 2] > board[0][i - 1] ? board[0][i - 2] : board[0][i - 1]) + sticker[1][i];
	}
}

int main()
{
	int T;

	cin >> T;
	for (int i = 0; i < T; i++){
		int n;
		int sticker[2][100000];
		int board[2][100000];

		cin >> n;
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < n; k++)
				cin >> sticker[j][k];
		}
		long score = 0;
		if (n == 1){
			score = sticker[0][0] > sticker[1][0] ? sticker[0][0] : sticker[1][0];
			cout << score << endl;
			continue;
		}
		set_score(sticker, board, n);
		score = board[0][n - 1] > board[1][n - 1] ? board[0][n - 1] : board[1][n - 1];
		cout << score << endl;
	}
	return (0);
}
