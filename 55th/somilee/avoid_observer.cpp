#include <iostream>
#include <queue>

using namespace std;

int n;
int b[7][7];
queue<pair<int, int> > Q;
int main(void) {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			char c; cin >> c;
			if (c == 'T')
				b[i][j] = -1;
			if (c == 'S') {
				b[i][j] = -2;
				Q.push({i, j});
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++)
			check_T(cur, dx[i], dy[i]);
	}
}