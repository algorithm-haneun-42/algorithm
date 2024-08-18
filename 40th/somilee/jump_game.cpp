#include <iostream>
#include <queue>

using namespace std;

int b[2][100005];
int main(void) {
	int n, k; cin >> n >> k;
	string l,r; cin >> l >> r;
	queue<pair<int, int> > Q;
	Q.push({0,0});
	while(!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		if (cur.second >= n-1) {
			cout << 1 << endl;
			return 0;
		}
		if (cur.second - 1 >= 0 && b[cur.first][cur.second - 1] == 1)
			Q.push({cur.first, cur.second - 1}); b[cur.first][cur.second - 1] = b[cur.first][cur.second] + 1;
		if (cur.second + 1 < n && b[cur.first][cur.second + 1] == 1)
			Q.push({cur.first, cur.second + 1}); b[cur.first][cur.second + 1] = b[cur.first][cur.second] + 1;
		if (cur.second + k < n && b[(cur.first + 1)%2][cur.second + k] == 1)
			Q.push({(cur.first + 1)%2, cur.second + k}); b[(cur.first + 1)%2][cur.second + k] = b[cur.first][cur.second] + 1;
		}
	}
}