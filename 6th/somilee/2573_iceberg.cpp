#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	int n,m;
	cin >> n >> m;

	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			cin >> board[i][j];
		}
	}
	int num;
	int year;
	for (year = 0; year <= 10; year ++)
	{
		bool vis[300][300] = {0};
		num = 0;
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{
				if (board[i][j] <= 0 || vis[i][j] == 1)
					continue;
				num ++;
				queue <pair<int,int> > Q;
				vis[i][j] = 1;
				Q.push({i,j});
				while (!Q.empty())
				{
					pair<int,int> cur = Q.front();
					Q.pop();
					int water = 0;
					for (int dir = 0; dir < 4; dir ++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (board[nx][ny] <= 0 && vis[nx][ny] == 0)
							water ++;
						if (board[nx][ny] <= 0 || vis[nx][ny] == 1)
							continue;
						vis [nx][ny] = 1;
						Q.push({nx,ny});
					}
					board[cur.X][cur.Y] -= water;
				}
			}
		}
		if (num >= 2)
			break;
	}
	if (num <= 1)
		year = 0;
	cout << year;
}
