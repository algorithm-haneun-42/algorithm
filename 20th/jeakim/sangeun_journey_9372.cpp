#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	vector<int> g[1001];

	cin >> t;
	for (int i = 0; i < t; i++){
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < m; j++){
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		bool chk[1001] = {0};
		int cnt = 0;

		chk[1] = 1;
		for (auto nxt : g[1])
			pq.push({nxt, 1});
		while (cnt < n - 1){
			int a, b;
			b = pq.top().first;
			a = pq.top().second;
			pq.pop();
			if(chk[b])
				continue;
			cnt++;
			chk[b] = 1;
			for(int nxt : g[b])
				if (!chk[nxt])
					pq.push({nxt, b});

		}
		cout << cnt << '\n';
	}
	return (0);
}