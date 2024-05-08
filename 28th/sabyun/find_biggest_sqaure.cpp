#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int col = board[0].size();
	int row = board.size();
	cout << col << row << endl;
	int squere = 0;
	for(int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
		{
			if(board[i][j] == 0)
				continue;
			else
				{
					int num = 0;
					for (int k = i>j ? j:i; k < col; k++)
					{
						if(i+k < col &&board[i+k][j] == 0)
							break;
						if(i+j < col && board[i][j+k] == 0)
							break;
						if(i+k < col && i+j < col && board[i+k][j+k] == 0)
							break;
						num++;
					}
					squere = max(squere,num);
				}
		}
	}
    return 0;
}
int main ()
{
	vector<vector<int>> map = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
	vector<vector<int>> map2 = {{{0,0,1,1},{1,1,1,1}}};
	solution(map);
}