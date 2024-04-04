#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

tuple<int, int, int> edge[100005];
vector<int> parent(10005, -1);

int	find(int x)
{
	if (parent[x] < 0)
		return(x);
	return parent[x] = find(parent[x]);
}

int	is_diff_group(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return (1);
	if (parent[x] == parent[y]) parent[x]--;
	if (parent[x] < parent[y]) parent[y] = x;
	else parent[x] = y;
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		edge[i] = {c, a, b};
	}
	sort(edge, edge+m);
	int cnt = 0;
	int add = 0;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		tie(z, x, y) = edge[i];
		if(is_diff_group(x, y) == 1)
			continue;
		add += z;
		cnt++;
		if (cnt == n-1)
			break;
	}
	cout << add;
}