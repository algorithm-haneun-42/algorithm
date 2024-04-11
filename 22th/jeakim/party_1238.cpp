#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x;
	int INF = 1e9 + 1;
	int d[1001];
	vector <pair<int, int> > adj[1001];
	
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}

	int max_n = 0;
	for (int st = 1; st <= n; st++){
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
		for (int i = 1; i <= n; i++)
			d[i] = INF;
		d[st] = 0;
		pq.push({d[st], st});
		while (!pq.empty()){
			auto cur = pq.top();
			pq.pop();
			if (d[cur.second] != cur.first)
				continue;
			for (auto nxt : adj[cur.second]){
				if (d[nxt.second] <= d[cur.second] + nxt.first)
					continue;
				d[nxt.second] = d[cur.second] + nxt.first;
				pq.push({d[nxt.second], nxt.second});
			}
		}
		max_n = max(max_n, d[x]);
	}
	cout << max_n << '\n';
	return (0);
}