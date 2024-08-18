#include <iostream>
#include <queue>

using namespace std;

int n, m, t;
int ans = 0xfffffff;
int map[105][105];
int vis[105][105];
pair<int, int> s;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int main(void) {
	cin >> n >> m >> t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				s = {i, j};
		}
	}
	queue<pair<int, int> >Q;
	Q.push({0, 0});
	vis[0][0] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if (map[x][y] == 1 || vis[x][y] > 0)
				continue;
			Q.push({x, y});
			vis[x][y] = vis[cur.first][cur.second] + 1;
		}
	}
	if (vis[n-1][m-1] != 0)
		ans = min(ans, vis[n-1][m-1] - 1);
	if (vis[s.first][s.second] != 0)
		ans = min(ans, vis[s.first][s.second] + n - 1 - s.first + m - 1 - s.second - 1);
	if (ans <= t)
		cout << ans << endl;
	else
		cout << "Fail\n";
	return 0;
}