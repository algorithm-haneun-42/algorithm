#include <string>
#include <vector>
#include <cmath>
using namespace std;
int is_game_over(vector<string> &board ,int player)
{
	int n = board.size();
	int m = board[0].size();
	int win = 1;
	for(int i = 0; i<n; i++)
	{
		win = 1;
		for(int j = 0; j<m; j++)
		{
			if(board[j][i] != player){
				win = 0;
				break;
			}
		}
		if(win == 1)
		return 1;
	}

	for(int i = 0; i<n; i++)
	{
		win = 1;
		for(int j = 0; j<m; j++)
		{
			if(board[i][j] != player){
				win = 0;
				break;
			}
		}
		if(win == 1)
		return 1;
	}

	for(int i = 0; i<n; i++)
	{
		win = 1;
		if(board[i][i] != player){
			win = 0;
			break;
		}
	}
	if(win == 1)
		return 1;
	for(int i = 0; i<n; i++)
	{
		win = 1;
		if(board[i][n - i -1] != player){
			win = 0;
			break;
		}
	}
	if(win == 1)
		return 1;
	return 0;
}
int solution(vector<string> board) {
	int n = board.size();
	int m = board[0].size();
	int mark_o = 0;
	int mark_x = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(board[i][j] == 'O')
				mark_o++;
			if(board[i][j] == 'X')
				mark_x++;
		}
	}
	if(mark_o < mark_x)
		return 0;
	if(mark_o == 0 && mark_x == 0)
		return 1;
	if (abs(mark_o - mark_x) > 1)
		return 0;
	int o_win = 0;
	int x_win = 0;
	o_win = is_game_over(board,'O');		
	x_win = is_game_over(board,'X');
	if(o_win == 1 && x_win == 1)
		return 0;
	if(x_win == 1 && mark_o > mark_x)
		return 0;
	if(o_win == 1 && mark_o <= mark_x)
		return 0;
    return 1;
}

int main()
{
	vector<string> map ={
		"XO.", "OX.", "OOX"
	};
	vector<string> map2 ={
		"OXX", ".OX", "..O"
	};
	vector<string> map3 ={
		"XXX", "OO.", "XOO"
	};
	vector<string> map4 ={
		"X..", "XOO", "XOO"
	};
	printf("%d\n",solution(map));
	printf("%d\n",solution(map2));
	printf("%d\n",solution(map3));
	printf("%d\n",solution(map4));
}