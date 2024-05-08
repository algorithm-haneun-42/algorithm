#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int col = board[0].size();
	int row = board.size();
	//cout << col << row << endl;
	int squere = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(board[i][j] == 0)
				continue;
			else
				{
					int num = 0;
					for (int k = 0; k < col; k++)
					{
						if(i+k >= row || j+k >= col) 
							break;
						else if(board[i+k][j+k] == 0 || board[i+k][j] == 0 || board[i][j+k] == 0)
							break;
						num++;
					}
					squere = max(squere,num);
				}
		}
	}
    return squere * squere;
}
int main ()
{
	vector<vector<int>> map = {{0,1,1,1},{1,1,0,1},{1,1,1,1},{0,0,1,0}};
	vector<vector<int>> map2 = {{{0,0,1,1},{1,1,1,1}}};
	vector<vector<int>> map3 = {{0,1},{1,1},{0,1}};
	cout << solution(map) << " "  << solution(map2) << " " <<solution(map3) << endl;
}