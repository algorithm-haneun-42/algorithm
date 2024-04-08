#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int d[105][105];
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <=n; j++)
		{
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 9900002;
		}
	}
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (d[i][j] == 9900002)
				cout << "0 ";
			else
				cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	return (0);
}
