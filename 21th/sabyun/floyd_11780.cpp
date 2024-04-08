#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int city[102][102];
	int next_city[102][102];
	int n, m; cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j <=n; j++)
		{
			if(i == j)
				city[i][j] =0;
			else
				city[i][j] = 120000000;
			next_city[i][j] = j;
		}
	}

	for(int i =0; i<m; i++)
	{
		int a,b,c; cin >> a>> b >> c;
		if(city[a][b] >c)
			city[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if(city[i][j] > city[i][k] + city[k][j])
				{
					city[i][j] = city[i][k] + city[k][j];
					next_city[i][j] = next_city[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(city[i][j] == 120000000)
				cout << "0 ";
			else
				cout << city[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(i==j || city[i][j] == 120000000)
				cout << "0" << endl;
			else
				{
					int now =i;
					int num = 1;
					int que[105] = {0};
					que[0] = i;
					while(now != j)
					{
						now = next_city[now][j];
						que[num] = now;
						num++;
					}
					que[num-1] = j;
					cout << num << " ";
					for(int k = 0; k<num; k++)
						cout << que[k] << " ";
					cout << endl;
				}
		}
	}
}