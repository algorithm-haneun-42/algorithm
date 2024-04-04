#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k; 
tuple<long long, int, int> edge[100005];
int elec[1005];
int parent[100005];

int	find(int x)
{
	if (x == parent[x])
		return(x);
	return parent[x] = find(parent[x]);
}

int	is_diff_group(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return (1);
	if (parent[x] < parent[y]) parent[y] = x;
	else parent[x] = y;
	return (0);
}

int is_elec_group(int x, int y)
{
	for(int i = 0; i < k; i++)
	{
		if (find(x) ==  find(elec[i]))
		{
			for(int j = 0; j < k; j++)
			{
				if (find(y) ==  find(elec[j]))
					return (1);
			}
		}
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
	{
		int e; cin >> e;
		elec[i] = e;
	}
	for(int i = 0; i < m; i++)
	{
		int a, b; long long c; cin >> a >> b >> c;
		edge[i] = {c, a, b};
	}
	sort(edge, edge+m);
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	int cnt = 0;
	long long add = 0;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		tie(z, x, y) = edge[i];
		if(is_elec_group(x, y) == 1 || is_diff_group(x, y) == 1)
			continue;
		add += z;
		cnt++;
		if (cnt == n-1)
			break;
	}
	cout << add;
}