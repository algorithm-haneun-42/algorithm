#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int INF = 1e9 + 1;

void dijkstra(vector <pair<int, int> > adj[1001], int d[1001], int n, int st)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq_go;
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	d[st] = 0;
	pq_go.push({d[st], st});
	while (!pq_go.empty()){
		auto cur = pq_go.top();
		pq_go.pop();
		if (d[cur.second] != cur.first)
			continue;
		for (auto nxt : adj[cur.second]){
			if (d[nxt.second] <= d[cur.second] + nxt.first)
				continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq_go.push({d[nxt.second], nxt.second});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, x;
	int d[1001];
	int d_rvs[1001];
	vector <pair<int, int> > adj[1001];
	vector <pair<int, int> > adj_rvs[1001];
	
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj_rvs[v].push_back({w, u});
	}

	int max_n = 0;
	dijkstra(adj, d, n, x);
	dijkstra(adj_rvs, d_rvs, n, x);
	for (int i = 1; i <= n; i++)
		max_n = max(max_n, d[i] + d_rvs[i]);
	cout << max_n << '\n';
	return (0);
}
