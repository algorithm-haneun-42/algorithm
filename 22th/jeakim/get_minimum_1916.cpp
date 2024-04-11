#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<pair<int, int> > adj[1001];
	const int INF = 1e9 + 1;
	int d[1001];

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		d[i] = INF;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}

	int st, end;
	cin >> st >> end;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
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
	cout << d[end] << '\n';
	return (0);
}