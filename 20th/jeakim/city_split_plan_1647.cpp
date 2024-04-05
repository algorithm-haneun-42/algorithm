#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<pair<int, int> > g[100001];

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({c, b});
		g[b].push_back({c, a});
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int>> > pq;
	int chk[100001] = {0};
	int cost = 0;
	int cnt = 0;
	int max_cost = 0;

	chk[1] = 1;
	for(auto nxt : g[1])
		pq.push({nxt.first, 1, nxt.second});
	while (cnt < n - 1){
		int a, b, c;
		tie(c, a, b) = pq.top();
		pq.pop();
		if (chk[b])
			continue;
		chk[b] = 1;
		cost += c;
		max_cost = max(max_cost, c);
		cnt++;
		for(auto nxt : g[b])
			if(!chk[nxt.second])
				pq.push(make_tuple(nxt.first, b, nxt.second));
	}
	cout << cost - max_cost << '\n';
	return (0);
}