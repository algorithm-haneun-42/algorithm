#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> vt[1001], int visited[1001], int n, int idx)
{
	visited[idx] = 1;
	for (int i = 0; i < vt[idx].size(); i++){
		int point = vt[idx][i];
		if (visited[point] == 0){
			dfs(vt, visited, n, point);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> vt[1001];
	int visited[1001] = {0};
	int cnt = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;

		cin >> u >> v;
		vt[u].push_back(v);
		vt[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		if (visited[i] == 0){
			cnt++;
			dfs(vt, visited, n, i);
		}
	}
	cout << cnt << endl;
	return (0);
}
