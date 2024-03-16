#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> vt[1001], int visited[1001], int n, int idx)
{
	queue<int> q;

	visited[idx] = 1;
	q.push(idx);
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		int vt_size = vt[cur].size();
		for (int i = 0; i < vt_size; i++){
			int next = vt[cur][i];
			if(visited[next] == 0){
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> vt[1001];
	int visited[1001] = {0};
	int cnt = 0;
	int n, m;
	
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
			bfs(vt, visited, n, i);
		}
	}
	cout << cnt << endl;
	return (0);
}
