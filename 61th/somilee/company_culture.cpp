#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,i,w;
int b[100005];
vector<int> v[100005];
int main(void) {
	cin >> n >> m;
	for(int j = 1; j <= n; j++) {
		int num; cin >> num;
		if(num > 0)
			v[num].push_back(j);
	}
	for(int j = 0; j < m; j++) {
		cin >> i >> w;
		queue<int> Q;
		b[i] += w;
		for(int a: v[i])
			Q.push(a);
		while(!Q.empty()) {
			int cur = Q.front(); Q.pop();
			b[cur] += w;
			for(int a: v[cur])
				Q.push(a);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << b[i] << ' ';
	cout << endl;
}