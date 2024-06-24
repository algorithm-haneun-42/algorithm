#include <iostream>
#include <queue>

using namespace std;

int n, m;
int c[5005][5005];
const int INF = 1e9+10;
int main(void) {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			c[i][j] = INF;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		c[a][b] = 1; c[b][a] = 1;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 1; i <= n; i++) {
		c[i][i] = 0;
		int sum = 0;
		for(int j = 1; j <= n; j++)
			sum += c[i][j];
		pq.push({sum, i});
	}
	cout << pq.top().second <<endl;
	return 0;
}