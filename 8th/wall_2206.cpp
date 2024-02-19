#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[1000][1000];
bool b[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(void)
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	
	int cnt = 0;
	queue<pair<int, int> > Q;
	bool vis[1000][1000] = {0};
	vis[0][0] = 1;
	Q.push({0, 0});
	int path = 0;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			path++;
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] == 1)
				continue;
			if (board[nx][ny] == 1)
			{
				if (b[nx][ny] == 1)
					continue;
				if (cnt != 0)
					continue;
				cnt++;
			}
			vis[nx][ny] = 1;
			Q.push({nx, ny});					
		}
	}
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 	{
	// 		// if (board[i][j] == 0 || vis[i][j] == 1)
	// 		// 	continue;
	// 		queue<pair<int, int> > Q;
	// 		vis[i][j] = 1;
	// 		Q.push({i, j});
	// 		while (!Q.empty())
	// 		{
	// 			pair<int, int> cur = Q.front();
	// 			Q.pop();
	// 			for(int dir = 0; dir < 4; dir++)
	// 			{
	// 				int nx = cur.X + dx[dir];
	// 				int ny = cur.Y + dy[dir];
	// 				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
	// 					continue;
	// 				if (vis[nx][ny] == 1 || board[nx][ny] == 0)
	// 					continue;
	// 				vis[nx][ny] = 1;
	// 				Q.push({nx, ny});					
	// 			}
	// 		}
	// 	}
	// }
}