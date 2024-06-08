#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define Y second
#define X first

int n, m;
int d[50005];
const int INF = 1e9+10;
vector<pair<int, int> > adj[50005];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	fill(d, d+n+1, INF);

	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	d[1] = 0;
	pq.push({d[1], 1});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;
		for(auto nxt : adj[cur.Y]){
			if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
			d[nxt.Y] = d[cur.Y]+nxt.X;
			pq.push({d[nxt.Y], nxt.Y});
		}
	}
	for(int i = 1; i <= n; i++){
		if(d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}
}