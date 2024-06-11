#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> b[55];

int main(void) {
	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			char c; cin >> c;
			if (c == 'Y') {
				b[i].push_back(j);
				b[j].push_back(i);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int vis[55] = {0};
		queue<int> Q;
		int cnt = 0;
		for(int x : b[i]) {
			if (vis[x] != 1)
				cnt++;
			vis[x] = 1;
			for(int y : b[x]) {
				if (vis[y] == 1 || y == i)
					continue;
				vis[y] = 1;
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}