#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
int deg[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int num; cin >> num;
		int a; cin >> a;
		for(int j = 1; j < num; j++)
		{
			int b; cin >> b;
			adj[a].push_back(b);
			deg[b]++;
			a = b;
		}
	}
	queue<int> q;
	queue<int> line;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 0)
			q.push(i);
	}
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		line.push(cur);
		for(int i : adj[cur])
		{
			deg[i]--;
			if(deg[i] == 0)
				q.push(i);
		}
	}
	for(int i : deg)
	{
		if(deg[i] != 0)
		{
			cout << '0';
			return (0);
		}
	}
	while(!line.empty())
	{
		cout << line.front() << '\n';
		line.pop();
	}
}