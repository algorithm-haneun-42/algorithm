#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topology(vector<int> g[32001], int idg[32001], int n){
	queue<int> q;
	
	for (int i = 1; i <= n; i++)
		if (idg[i] == 0)
			q.push(i);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int nxt : g[cur]){
			idg[nxt]--;
			if (idg[nxt] == 0)
				q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> g[32001];
	int idg[32001] = {0};
	queue<int> q;
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		idg[b]++;
	}
	topology(g, idg, n);
	return (0);
}
