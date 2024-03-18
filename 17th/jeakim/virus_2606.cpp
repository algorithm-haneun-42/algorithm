#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<int> g[101], int visited[101], int idx)
{
	visited[idx] = 1;
	for (int i = 0; i < g[idx].size(); i++){
		if (visited[g[idx][i]] == 0)
			dfs(g, visited, g[idx][i]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> g[101];
	int visited[101] = {0};

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(g, visited, 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (visited[i] == 1)
			cnt++;
	cout << cnt - 1 << '\n';
	return (0);
}