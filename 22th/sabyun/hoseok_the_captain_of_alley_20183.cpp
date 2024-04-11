#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
using namespace std;
# define INF LONG_MAX

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<long,long>> r[100005];
	long len[100005];
	set<int> s[100005];
	priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
	long n,m,st,ed,coin; cin >>n >> m >>st >> ed >> coin;
	fill(len,len+n+1,INF);
	for (long i =0; i< m; i++)
	{
		long a,b,c; cin >> a>>b>>c;
		r[a].push_back({c,b});
	}
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
			s[nxt.second].insert(nxt.first);
			cout << "rote = " << nxt.second << "cost = " << nxt.first << endl;
			pq.push({len[nxt.second],nxt.second});
		}
	}
	long ret = INF;

	for (int i =1; i<=n; i++)
	{
		if(ret > len[i] && i !=st && i != ed)
			ret = len[i];
		cout << ret <<len[i]<<endl; 
	}
	if(ret > coin)
		cout << "-1"<<endl;
	else
		cout << ret << endl;
}