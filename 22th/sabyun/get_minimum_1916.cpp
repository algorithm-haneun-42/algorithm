#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
# define INF 100000005 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<int,int>> r[100005];
	int len[100005];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int n,m; cin >>n >> m;
	fill(len,len+n+1,INF);
	for (int i =0; i< m; i++)
	{
		int a,b,c; cin >> a>>b>>c;
		r[a].push_back({c,b});
	}
	int st,ed; cin >>st >> ed;
	len[st] = 0;
	pq.push({len[st],st});
	while(!pq.empty())
	{
		auto qt = pq.top(); pq.pop();
		if(len[qt.second] != qt.first) continue;
		for(auto nxt: r[qt.second])
		{
			if(len[nxt.second] <= len[qt.second] + nxt.first) continue;
			len[nxt.second] = len[qt.second] + nxt.first;
			pq.push({len[nxt.second],nxt.second});
		}
	}
	cout << len[ed] << endl;
}