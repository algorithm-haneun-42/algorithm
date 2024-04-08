#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;
	int item[101] = {0};
	int d[101][101];
	int nxt[101][101] = {0};
	int cnt = 0;

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		item[i + 1] = t;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 1500001;
		}
	}
	for (int i = 0; i < r; i++){
		int a, b, l;
		cin >> a >> b >> l;
		d[a][b] = min(d[a][b], l);
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (d[i][j] )
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	return (0);
}