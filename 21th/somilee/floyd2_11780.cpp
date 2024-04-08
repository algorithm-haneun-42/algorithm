#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int INF = 0x3f3f3f3f;
int d[101][101];
int p[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	 int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		fill(d[i], d[i]+1+n, INF);
	for(int i = 1; i <= n; i++)
		fill(p[i], p[i]+1+n, INF);
	for(int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		p[a][b] = b;
	}
	for(int i = 1; i <= n; i++)
		d[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j++)
			{
				if (d[i][j]> d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k];
				}
			
			}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if (d[i][j] == INF)
				cout << "0 ";
			else
				cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			vector<int> path;
			int st = i;
			while(st != j && st != INF)
			{
				path.push_back(st);
				st = p[st][j];
			}
			if (st == INF)
				cout << '0';
			else
			{
				path.push_back(j);
				if(path.size()  == 1)
					cout << '0';
				else
				{
					cout << path.size() << ' ';
					for(int k = 0; k < path.size(); k++)
						cout << path[k] << ' ';
				}
			}
			cout << '\n';
		}
	}
}