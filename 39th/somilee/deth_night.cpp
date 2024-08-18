#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int n, r1, c1, r2, c2;
int v[205][205];
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int main(void) {
	cin >> n >> r1 >> c1 >> r2 >> c2;
	queue<pair<int, int> > Q;
	Q.push({r1, c1});
	v[r1][c1] = 1;
	while(!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		if (cur.X == r2 && cur.Y == c2) {
			cout << v[cur.X][cur.Y] - 1<< endl;
			return 0;
		}
		for(int i = 0; i < 6; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (v[nx][ny] > 0)
				continue;
			v[nx][ny] = v[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	cout << "-1\n";
	return 0;
}