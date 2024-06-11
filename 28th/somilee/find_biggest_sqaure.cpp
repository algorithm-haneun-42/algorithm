#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	get_size(int i, int j, vector<vector<int>> board) {
	int a = 1;
	while (i + a < board.size() && j + a < board[0].size()) {
		for(int b = 0; b <= a; b++) {
			if (board[i+a][j+b] == 0 || board[i+b][j+a] == 0)
				return (a);
		}
		a++;
	}
	return a;
}

int solution(vector<vector<int>> board)
{
	int ans = 0;
    for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 1)
				ans = max(ans, get_size(i, j, board));
		}
	}
	return (ans*ans);
}

int main(void) {
	vector<vector<int>> board;
	board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
	cout << solution(board) << '\n';
}

/*
{0,1,1,1},
{1,1,1,1},
{1,1,1,1},
{0,0,1,0}
*/