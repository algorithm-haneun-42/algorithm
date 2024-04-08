#include <iostream>
#include <algorithm>
using namespace std;

int INF = 0x3f3f3f3f;
int d[405][405];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		fill(d[i], d[i]+1+n, INF);
	for(int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for(int i = 1; i <= n; i++)
		d[i][i] = 0;
	int sum = INF;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if( d[i][j] != 0 && d[j][i] != 0 && d[i][j] != INF && d[j][i] != INF)
				sum = min(sum, d[i][j] + d[j][i]);
		}
	}
	if (sum == INF)
		cout << '-1';
	else
		cout << sum;
	return (0);
}