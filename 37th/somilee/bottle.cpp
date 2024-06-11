#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstdlib>
#include <algorithm>

using namespace std;

int abc_vis[205][205][205];
int main(void) {
	int a, b, c; cin >> a >> b >> c;
	int vis[5000] = {0};
	vector<int> V;
	queue<tuple <int, int, int> > Q;
	Q.push({0, 0, c}); abc_vis[0][0][c] = 1;
	vis[c] = 1; V.push_back(c);
	while (!Q.empty()) {
		int a1, b1, c1;
		tie(a1, b1, c1) = Q.front(); Q.pop();
		if(a1 == 0 && vis[c1] == 0) {
			vis[c1] = 1;
			V.push_back(c1);
		}
		if (a1 > 0) {
			if (b1 < b && abc_vis[a1 - min(a1, b - b1)][b1 + min(a1, b - b1)][c1] == 0) {
				abc_vis[a1 - min(a1, b - b1)][b1 + min(a1, b - b1)][c1] = 1;
				Q.push({a1 - min(a1, b - b1), b1 + min(a1, b - b1), c1});
			}
			if (c1 < c && abc_vis[a1 - min(a1, c - c1)][b1][c1 + min(a1, c - c1)] == 0) {
				abc_vis[a1 - min(a1, c - c1)][b1][c1 + min(a1, c - c1)] = 1;
				Q.push({a1 - min(a1, c - c1), b1, c1 + min(a1, c - c1)});
			}
		}
		if (b1 > 0) {
			if (a1 < a && abc_vis[a1 + min(b1, a - a1)][b1 - min(b1, a - a1)][c1] == 0) {
				abc_vis[a1 + min(b1, a - a1)][b1 - min(b1, a - a1)][c1] = 1;
				Q.push({a1 + min(b1, a - a1), b1 - min(b1, a - a1), c1});
			}
			if (c1 < c && abc_vis[a1][b1 - min(b1, c - c1)][c1 + min(b1, c - c1)] == 0) {
				abc_vis[a1][b1 - min(b1, c - c1)][c1 + min(b1, c - c1)] = 1;
				Q.push({a1, b1 - min(b1, c - c1), c1 + min(b1, c - c1)});
			}
		}
		if (c1 > 0) {
			if (a1 < a && abc_vis[a1 + min(c1, a - a1)][b1][c1 - min(c1, a - a1)] == 0) {
				abc_vis[a1 + min(c1, a - a1)][b1][c1 - min(c1, a - a1)] = 1;
				Q.push({a1 + min(c1, a - a1), b1, c1 - min(c1, a - a1)});
			}
			if (b1 < b && abc_vis[a1][b1 + min(c1, b - b1)][c1 - min(c1, b - b1)] == 0) {
				abc_vis[a1][b1 + min(c1, b - b1)][c1 - min(c1, b - b1)] = 1;
				Q.push({a1, b1 + min(c1, b - b1), c1 - min(c1, b - b1)});
			}
		}
	}
	sort(V.begin(), V.end());
	for(int a : V)
		cout << a << ' ';
	return 0;
}