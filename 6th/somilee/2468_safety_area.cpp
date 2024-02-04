#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second
int board[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			cin >> board[i][j];
	int max_num = 0;
	int water_height = 0;
	while (1)
	{
		int num = 0;
		bool vis[100][100] = {0};
		for (int i = 0; i < n; i ++)
		{
			for (int j = 0; j < n; j ++)
			{
				if (board[i][j] <= water_height || vis[i][j] == 1)
					continue;
				num ++;
				queue<pair<int, int> > Q;
				vis[i][j] = 1;
				Q.push({i,j});
				int area = 0;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir ++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)
							continue;
						if (vis[nx][ny] == 1 || board[nx][ny] <= water_height)
							continue;
						vis[nx][ny] = 1;
						Q.push({nx,ny});
					}
				}
			}
		}
		if (num == 0)
			break;
		max_num = max(max_num, num);
		water_height ++;
	}
	cout << max_num;
}
