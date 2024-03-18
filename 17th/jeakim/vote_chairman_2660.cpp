#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> g[101], int visited[101], int idx, int &cnt, int point[101])
{
	visited[idx] = 1;
	for (int i = 0; i < g[idx].size(); i++){
		if (visited[g[idx][i]] == 0){
			cnt++;

		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<int> g[101];
	int point[101] = {0};

	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
		{
			int u, v;
			cin >> u >> v;
			if (u == -1 && v == -1)
				break;
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++){
		int visited[101] = {0};
		int cnt = 0;
		bfs(g, visited, i, cnt, point);
		for (int k = 1; k <= n; k++)
			cout << visited[k] << ' ';
		cout << '\n';
	}
	return (0);
}