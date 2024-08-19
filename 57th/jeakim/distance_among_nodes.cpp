#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 10001;

int n, m;
vector<pair<int, int> > v[1001];
int dist[1001] = {INF};

void	dijkstra_bfs(int st)
{
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[st] = 0;

	pq.push({0, st});
	while (!pq.empty()){
		int cur_node = pq.top().second;
		int cur_dist = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < v[cur_node].size(); i++){
			int nxt_node = v[cur_node][i].first;
			int nxt_dist = cur_dist + v[cur_node][i].second;

			if (nxt_dist < dist[nxt_node]){
				dist[nxt_node] = nxt_dist;
				pq.push({-1 * nxt_dist, nxt_node});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << endl;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	for (int i = 0; i < m; i++){
		int st, en;
		cin >> st >> en;
		dijkstra_bfs(st);
		cout << dist[en] << endl;
	}
	return (0);
}