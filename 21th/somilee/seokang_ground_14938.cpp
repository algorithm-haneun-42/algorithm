#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int INF = 0x3f3f3f3f;
int f[101];
int d[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r; cin >> n >> m >> r;
	for(int i = 1; i <= n; i++)
	{
		int item; cin >> item;
		f[i] = item;
	}
	for(int i = 1; i <= n; i++)
		fill(d[i], d[i]+1+n, INF);
	for(int i = 0; i < r; i++)
	{
		int a, b, l; cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
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
				}
			
			}

	int num = 0;
	for(int i = 1; i <= n; i++)
	{
		int ans = 0;
		for(int j = 1; j <= n; j++)
		{
			if (d[i][j] <= m)
				ans += f[j];
		}
		num = max(ans, num);
	}
	cout << num;
}