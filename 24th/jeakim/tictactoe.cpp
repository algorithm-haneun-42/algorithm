#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt_o = 0;
int cnt_x = 0;

void count_num(vector<string> board){
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[i].size(); j++){
			if (board[i][j] == 'O')
				cnt_o++;
			else if (board[i][j] == 'X')
				cnt_x++;
		}
	}
}

int check_bingo(vector<string> board, char c)
{
	int bingo = 0;
	for (int i = 0; i < 3; i++){
		if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
			bingo++;
		if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
			bingo++;
	}
	if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
		bingo++;
	if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
		bingo++;
	return (bingo);
}

int check_board(vector<string> board){
	int bingo_o = check_bingo(board, 'O');
	int bingo_x = check_bingo(board, 'X');

	if (cnt_o < cnt_x)
		return (0);
	if (cnt_o > cnt_x + 1)
		return (0);
	if (bingo_o > 0 && cnt_o == cnt_x)
		return (0);
	if (bingo_x > 0 && cnt_o > cnt_x)
		return (0);
	if (bingo_o > 0 && bingo_x > 0)
		return (0);
	return (1);
}

int solution(vector<string> board) {
    int answer = -1;

	count_num(board);
	answer = check_board(board);
    return answer;
}

int main()
{
	vector<string> board = {"OXO",
"XOX",
"OXO"};
	int answer = solution(board);
	cout << answer << endl;

	return (0);
}