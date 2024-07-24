#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[1005];
int deg[1005];
int ans[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}
	int cnt = 1;
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
			ans[i] = cnt;
		}
	}
	while (!q.empty()) {
		cnt++;
		int q_size = q.size();
		for(int i = 0; i < q_size; i++) {
			int cur = q.front(); q.pop();
			for(int i : adj[cur]) {
				deg[i]--;
				if (deg[i] == 0) {
					q.push(i);
					ans[i] = cnt;
				}
			}
		}
	}
	for(int i : deg) {
		if (deg[i] != 0) {
			cout << "0\n";
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
}