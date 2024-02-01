#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t ++)
	{
		int board[50][50] = { 0 };
		bool vis[50][50] = { 0 };
		int n, m, c_num;
		cin >> m >> n >> c_num;

		for(int i = 0; i < c_num; i ++)
		{
			int x,y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int num = 0;
		for(int i = 0; i < n; i ++)
		{
			for (int j = 0; j < m; j ++)
			{
				if (board[i][j] == 0 || vis[i][j] == 1)
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
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (vis[nx][ny] == 1 || board[nx][ny] == 0)
							continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
		cout << num << '\n';
	}
}
