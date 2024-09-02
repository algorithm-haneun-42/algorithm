#include <iostream>
#include <queue>

using namespace std;

int n,q,a,b,r,k,v;
int m[5001][5001];
int ans[5001];
int main(void) {
	cin >> n >> q;
	for(int i = 1; i < n; i++) {
		cin >> a >> b >> r;
		m[a][b] = r;
		m[b][a] = r;
	}
	while(q--) {
		cin >> k >> v;
		queue<pair<int, int> > Q;
		int vis[5001] = {0};
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			ans[i] = 0xfffffff;
		for(int i = 1; i <= n; i++)
			if(m[v][i] != 0) {
				Q.push({v, i});
				vis[i] = 1;
			}
		vis[v] = 1;
		while(!Q.empty()) {
			int from = Q.front().first;
			int to = Q.front().second;
			Q.pop();
			ans[to] = min(ans[from], m[from][to]);
			if(ans[to] >= k && ans[to] != 0xfffffff)
				cnt++;
			for(int i = 1; i <= n; i++)
				if(m[to][i] != 0 && vis[i] == 0) {
					Q.push({to, i});
					vis[i] = 1;
				}
		}
		cout << cnt << endl;
	}
}