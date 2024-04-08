#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	int box[1005][1005] = {0};
	for (int i = 1; i<= n; i++)
	{
		for(int j =1; j<=n; j++)
		{
			if(i == j)
				box[i][j] = 0;
			else
				box[i][j] = 100000002;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a,b,cost; cin >> a >> b >> cost;
		if(box[a][b] > cost)
			box[a][b] = cost;
	}
	for(int i = 1; i<=n; i++)
	{
		for (int j = 1; j <= n ;j++)
		{
			for(int k = 1; k<= n; k++)
			{
				if(box[j][k] > box[j][i] + box[i][k])
					box[j][k] = box[j][i] + box[i][k];
			}
		}
	}
	for (int i = 1; i<= n; i++)
	{
		for(int j =1; j<=n; j++)
		{
			if(box[i][j] == 100000002)
				cout << "0" << ' ';
			else
				cout << box[i][j] << ' ';
		}
		cout << endl;
	}
}