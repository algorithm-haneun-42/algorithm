#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, num;
int board[100][100];
int vis[100][100];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> num;

	for(int i = 0; i < num; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j = x1; j < x2; j++)
		{
			for(int k = y1; k < y2; k++)
			{
				board[j][k] = 1;
			}
		}
	}
	int cnt = 0;
	vector<int> a;
	for(int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (board[i][j] == 1 || vis[i][j] == 1)
				continue;
			cnt++;
			queue<pair<int, int> > Q;
			vis[i][j] = 1;
			Q.push({i,j});
			int area = 0;
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				area++;
				for (int dir = 0; dir < 4; dir ++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (vis[nx][ny] == 1 || board[nx][ny] == 1)
						continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			a.push_back(area);
		}
	}

	sort(a.begin(), a.begin() + cnt);
	cout << cnt <<'\n';
	for(int i = 0; i < cnt; i++)
		cout << a[i] << ' ';
}