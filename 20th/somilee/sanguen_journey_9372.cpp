#include <iostream>
#include <algorithm>
using namespace std;

int parent[1005];

int find(int x)
{
	if(x == parent[x])
		return (x);
	return find(parent[x]);
}

int is_diff_group(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return(1);
	parent[x] = y;
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		pair<int, int> edge[10005];
		int n, m; cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			edge[i] = {a, b};
		}
		sort(edge, edge+m);
		for(int i = 1; i <= n; i++)
			parent[i] = i;
		int cnt = 0;
		for(int i = 0; i < m; i++)
		{
			int x, y;
			tie(x, y) = edge[i];
			if(is_diff_group(x, y) == 1)
				continue;
			cnt++;
			if(cnt == n-1)
				break;
		}
		cout << cnt <<'\n';
	}
}