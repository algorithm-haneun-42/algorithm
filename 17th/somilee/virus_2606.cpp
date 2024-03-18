#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	vector<vector< int> > v(n+1);
	for(int i = 0; i < k; i++)
	{
		int f, t; cin >> f >> t;
		v[f].push_back(t);
		v[t].push_back(f);
	}
	queue<int> Q;
	Q.push(1);
	int vis[105] = {0};
	vis[1] = 1;
	int cnt = 0;
	while(!Q.empty())
	{
		int from = Q.front(); Q.pop();
		cnt++;
		while(v[from].size() != 0)
		{
			int to = v[from].back(); v[from].pop_back();
			if(vis[to] == 0)
			{
				Q.push(to);
				vis[to] = 1;
			}
		}
	}
	cout << cnt - 1 << '\n';
}

/*
7
0
*/