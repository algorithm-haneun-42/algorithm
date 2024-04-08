#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,r; cin >> n >> m >> r;
	int item[n+5];
	int zone[102][102] = {0};
	for (int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(i == j)
				zone[i][j] = 0;
			else
				zone[i][j] = 3200;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		item[i] = a;
	}
	for (int i = 1; i <= r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (zone[a][b] > c)
			zone[a][b] = c;
	}
	for (int k = 1; k <= n; k++)
	{
		for(int i = 1; i<=n; i++)
		{
			for(int j =1 ; j<=n; j++)
			{
				if(zone[i][j] > zone[k][i] + zone[j][k])
					zone[i][j] = zone[k][i] + zone[j][k];
			}
		}
	}
	int max = 0;
	int max_value = 0;
	for (int i = 1; i <= n; i++)
	{
		int value = 0;
		for (int k = 1; k <= n; k++)
		{
			if (zone[i][k] <= m)
				value += item[k];
		}
		if (max_value < value)
		{
			max_value = value;
			max = i;
		}
	}
	cout << max_value << endl;
}