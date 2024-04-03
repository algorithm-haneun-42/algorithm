#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int v, e;
	vector<pair<int, int> > g[10001];

	for (int i = 0; i < e; i++){
		int a, b, c;

		cin >> a >> b >> c;
		g[a].push_back(make_pair(a, b));
		g[b].push_back(make_pair(c, a));
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
	bool chk[10001] = {0};
	long long value = 0;
	int cnt = 0;

	chk[1] = 1;
	for (auto nxt : g[1])
		pq.push(make_tuple(nxt.first, 1, nxt.second));
	while(cnt < v - 1){
		int a, b, c;

		tie(c, a, b) = pq.top();
		pq.pop();
		if (chk[b])
			continue;
		value += c;
		chk[b] = 1;
		cnt++;
		for(auto nxt : g[b])
			if(!chk[nxt.second])
				pq.push(tie(nxt.first, b, nxt.second));
	}
	cout << value << '\n';
	return (0);
}
