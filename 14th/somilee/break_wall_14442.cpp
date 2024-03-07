#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	int n, m, k; cin >> n >> m >> k;

	int b[15][15] = {0};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char num; cin >> num;
			b[i][j] = num - '0';
		}
	}
	int k_num = 0;
	int v[15][15][11] = {0};
	queue<pair<int, int> > Q;
	v[0][0][0] = 1;
	Q.push({0, 0});
	while(!Q.empty())
	{
		pair<int, int> cur = Q.front();
		if (b[cur.X][cur.Y] == 1)
		{
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					v[i][j][k_num] = 0;
			k_num--;
		}
		Q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx == n-1 && ny == m-1)
			{
				cout << v[nx][ny][k_num] << '\n';;
				break;
			}
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (b[nx][ny] == 1)
			{
				if (v[nx][ny][k_num] == 0 && k_num < k)
				{
					v[nx][ny][k_num] = v[cur.X][cur.Y][k_num] + 1;
					k_num++;
				}
				continue;
			}
			if (v[nx][ny][k_num] != 0)
				continue;
			v[nx][ny][k_num] = v[cur.X][cur.Y][k_num] + 1;
			Q.push({nx, ny});
		}
	}
	cout << "-1" <<'\n';

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << b[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 		cout << v[i][j] << ' ';
	// 	cout << '\n';
	// }

}
/*
6 4 2
0000
1110
1000
0000
0111
0000
*/