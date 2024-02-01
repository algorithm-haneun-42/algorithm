#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void)
{
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t ++)
	{
		int board[300][300] = { 0 };
		bool vis[300][300] = { 0 };
		int l;
		cin >> l;

		queue<pair<int, int> > Q;
		pair<int, int> cur;
		pair<int, int> end;
		cin >> cur.X >> cur.Y;
		cin >> end.X >> end.Y;
		
		vis[cur.X][cur.Y] = 1;
		Q.push({cur.X,cur.Y});
		int min_num = 1000;
		int num;
		while(!Q.empty())
		{
			num = 0;
			pair<int,int> cur = Q.front();
			Q.pop();
			for(int dir = 0; dir < 8; dir++)
			{
				num ++;
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx >= l || ny < 0 || ny >= l) 
					continue;
				if(vis[nx][ny] || board[nx][ny] != 1) 
					continue;
				vis[nx][ny] = 1;
				Q.push({nx,ny});
			}
			min_num = min(min_num, num);
		}
		cout << min_num << '\n';
	}
}
