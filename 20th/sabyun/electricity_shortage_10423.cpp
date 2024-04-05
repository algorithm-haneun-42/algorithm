#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> p(100005,-1);

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
	int n,m,k;
	tuple<int,int,int> box[100005];

		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			int a;
			cin >> a;
			p[a] = 0;
		}
		for (int j = 0;  j < m; j++)
		{
			int cost,a,b;
			cin >> a>>b>>cost;
			box[j] = {cost,a,b};
		}
		sort(box,box+m);
		int cnt =0;
		int ret = 0;
		for(int j = 0 ; j < m; j++)
		{
			int cost,a,b;
			tie(cost,a,b) = box[j];
			if(!is_diff_group(a,b)) continue;
			cnt++;
			ret+=cost;
			if(cnt == n-1)
				break;
		}
		cout << ret<< '\n';
	return 0;	
}