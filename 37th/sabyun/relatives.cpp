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
	
	vector<int> r[100005];
	int len[100005];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int n; cin >>n;
	int st, ed ; cin >> st >> ed;
	fill(len,len+n+1,INF);
	for (int i =0; i< n; i++)
	{
		int a,b; cin >> a>>b;
		r[a].push_back(b);
	}
	len[st] = 1;
	pq.push({len[st],st});
	while(!pq.empty())
	{
		auto qt = pq.top(); pq.pop();
		if(len[qt.second] != qt.first) continue;
		for(int nxt: r[qt.second])
		{
			if(len[nxt] <= len[qt.second] + nxt) continue;
			len[nxt] = len[qt.second] + 1;
			pq.push({len[nxt],nxt});
		}
	}
	if(len[ed] == INF)
		cout << "-1" << endl;
	else
		cout << len[ed]<< endl;
}