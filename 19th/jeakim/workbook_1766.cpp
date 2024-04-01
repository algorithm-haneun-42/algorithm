#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topology(int n, vector<int> g[32001], int idg[32001])
{
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 1; i <= n; i++)
		if (idg[i] == 0)
			pq.push(i);
	while(!pq.empty()){
		int cur = pq.top();
		pq.pop();
		cout << cur << ' ';
		for (int nxt : g[cur]){
			idg[nxt]--;
			if (idg[nxt] == 0)
				pq.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> g[32001];
	int idg[32001] = {0};

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		idg[b]++;
	}
	topology(n, g, idg);
	return (0);
}
