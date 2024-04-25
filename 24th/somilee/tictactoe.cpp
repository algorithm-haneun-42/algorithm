#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> board;
int solution(vector<string> board) {
	int O_num = 0;
	int X_num = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if (board[i][j] == 'O')
				O_num ++;
			if (board[i][j] == 'X')
				X_num ++;
		}
	}
	if (O_num != X_num && O_num != X_num + 1)
		return 0;

	int O_bingo = 0;
	int X_bingo = 0;
	for(int i = 0; i < 3; i++){
		if ((board[i][0] == board[i][1])&&(board[i][1] == board[i][2])){
			if (board[i][0] == 'O')
				O_bingo ++;
			if (board[i][0] == 'X')
				X_bingo ++;
		}
		if ((board[0][i] == board[1][i])&&(board[1][i] == board[2][i])){
			if (board[0][i] == 'O')
				O_bingo ++;
			if (board[0][i] == 'X')
				X_bingo ++;
		}
	}
	if ((board[0][0] == board[1][1])&&(board[1][1] == board[2][2])){
		if (board[0][0] == 'O')
			O_bingo ++;
		if (board[0][0] == 'X')
			X_bingo ++;
	}
	if ((board[0][2] == board[1][1])&&(board[1][1] == board[2][0])){
		if (board[0][2] == 'O')
			O_bingo ++;
		if (board[0][2] == 'X')
			X_bingo ++;
	}
	if (O_bingo != 0 && X_bingo != 0)
		return 0;
	if (X_bingo != 0 && O_num == X_num + 1)
		return 0;
	if (O_bingo != 0 && O_num == X_num)
		return 0;
	
    return 1;
}

int main(void){
	board.push_back("...");
	board.push_back(".X.");
	board.push_back("...");
	cout << solution(board) << '\n';
}