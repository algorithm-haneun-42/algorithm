#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> p;

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
int comp(const tuple<int,int,int>&a, const tuple<int,int,int>&b)
{
	return get<0>(a) < get<0>(b);
}
int main()
{
	int n,m;
	vector<tuple<int,int,int>> box;

		cin >> n >> m;
		p.assign(m+1,-1);
		box.resize(m+1);
		for (int j = 0;  j < m; j++)
		{
			int cost,a,b;
			cin >> a>>b>>cost;
			box[j] = make_tuple(cost,a,b);
		}
		sort(box.begin(),box.end(),comp);
		int cnt =0;
		int ret = 0;
		for(int j = 0 ; j < m; j++)
		{
			int cost,a,b;
			tie(cost,a,b) = box[j];
			if(!is_diff_group(a,b)) continue;
			cnt++;
			ret+=cost;
			if(cnt == n-2)
				break;
		}
		cout << ret << '\n';
	return 0;	
}