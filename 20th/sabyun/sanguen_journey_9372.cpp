#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> p(1005,-1);

int find(int x)
{
	if(p[x]<0)
		return x;
	return p[x] = find(p[x]);
}
bool is_diff_group(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return 0;
	if (p[u] == p[v])
		p[u]--;
	if (p[u] < p[v])
		p[v] = u;
	else
		p[u] = v;
	return 1;
}
int main()
{
	int t,n,m;
	cin >> t;
	pair<int,int> box[1005];

	for (int i = 0; i< t; i++)
	{
		cin >> n >> m;
		for (int j = 0;  j < m; j++)
		{
			int a,b;
			cin >> a>>b;
			box[j] = {a,b};
		}
		sort(box,box+m);
		int cnt =0;
		for(int j = 0 ; j < m; j++)
		{
			int a,b;
			tie(a,b) = box[j];
			if(!is_diff_group(a,b)) continue;
			cnt++;
			if(cnt == n-1)
				break;
		}
		cout << cnt<< '\n';
		p.assign(1005,-1);
	}
	return 0;	
}