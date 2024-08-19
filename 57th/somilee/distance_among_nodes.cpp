#include <iostream>
#include <algorithm>
using namespace std;

int INF = 0xfffffff;
int d[1001][1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		fill(d[i], d[i]+1+n, INF);
	for(int i = 0; i < n-1; i++){
		int a, b, v; cin >> a >> b >> v;
		d[a][b] = v;
        d[b][a] = v;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for(int i = 1; i <= n; i++)
		d[i][i] = 0;
	for(int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        cout << d[s][e] << endl;
    }
}