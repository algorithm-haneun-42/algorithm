#include <iostream>
#include <queue>
#include <tuple>

#define X first
#define Y second
using namespace std;

int n, m, a, b, c, d;
char map[305][305];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int main() {
    cin >> n >> m >> a >> b >> c >> d;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> map[i][j];
	map[c][d] = '1';
	int vis[305][305] = {0};
	queue<pair<int, int> >Q;
	Q.push({a, b});
	vis[a][b] = 0;
	while(!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++) {
			int ax = cur.X + dx[i];
			int ay = cur.Y + dy[i];
			if(ax < 1 || ax > n || ay < 1 || ay > m || vis[ax][ay] > 0)
				continue;
			if (map[ax][ay] == '0') {
				vis[ax][ay] = vis[cur.X][cur.Y];
			}
			if (map[ax][ay] == '1') {
				vis[ax][ay] = vis[cur.X][cur.Y] + 1;
			}
			Q.push({ax, ay});
		}
	}
	cout << vis[c][d] << endl;
	return 0;
}


// int main() {
//     cin >> n >> m >> a >> b >> c >> d;
// 	for(int i = 1; i <= n; i++)
// 		for(int j = 1; j <= m; j++)
// 			cin >> map[i][j];
// 	for(int cnt = 1; cnt <= 300; cnt++) {
// 		int vis[300][300] = {0};
// 		queue<pair<int, int> >Q;
// 		Q.push({a, b});
// 		vis[a][b] = 1;
// 		while(!Q.empty()) {
// 			pair<int, int> cur = Q.front(); Q.pop();
// 			for(int i = 0; i < 4; i++) {
// 				int ax = cur.X + dx[i];
// 				int ay = cur.Y + dy[i];
// 				if(ax < 1 || ax >= n || ay < 1 || ay >= m || vis[ax][ay] == 1)
// 					continue;
// 				if (ax == c && ay == d) {
// 					cout << cnt << endl;
// 					return 0;
// 				}
// 				if (map[ax][ay] == '1') {
// 					map[ax][ay] = '0';
// 					vis[ax][ay] = 1;
// 					continue;
// 				}
// 				Q.push({ax, ay});
// 				vis[ax][ay] = 1;
// 			}
// 		}
// 	}
// 	return 0;
// }