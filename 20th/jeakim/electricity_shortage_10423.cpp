#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	vector<pair<int, int> > g[1001];
	int chk[1001] = {0};
	int cnt = 0;

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		int c;
		cin >> c;
		chk[c] = 1;
	}
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
	for (int i = 1; i <= n; i++)
		for (auto nxt : g[i])
			if (chk[i] == 1)
				pq.push({nxt.first, i, nxt.second});
	long long cost = 0;
	while (cnt < n - k){
		int u, v, w;
		tie(w, u, v) = pq.top();
		pq.pop();
		if(chk[v])
			continue;
		chk[v] = 1;
		cost += w;
		cnt++;
		for(auto nxt : g[v])
			if (!chk[nxt.second])
				pq.push({nxt.first, v, nxt.second});
	}
	cout << cost << '\n';
	return (0);
}
