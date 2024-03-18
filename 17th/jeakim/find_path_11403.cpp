#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> g[101], int visited[101], int idx, int flag){
	if (flag == 1)
		visited[idx] = 1;
	for (int i = 0; i < g[idx].size(); i++){
		if(visited[g[idx][i]] == 0)
			dfs(g, visited, g[idx][i], 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<int> g[101];

	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
		{
			int m;
			cin >> m;
			if (m == 1)
				g[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++){
		int visited[101] = {0};
		dfs(g, visited, i, 0);
		for (int k = 1; k <= n; k++)
			cout << visited[k] << ' ';
		cout << '\n';
	}
	return (0);
}
