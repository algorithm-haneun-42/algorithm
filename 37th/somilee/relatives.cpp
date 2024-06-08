#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> r[105];
int v[105];

int main(void) {
	int n; cin >> n;
	int a, b; cin >> a >> b;
	int m; cin >> m;
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		r[x].push_back(y);
		r[y].push_back(x);
	}
	queue<int> Q;
	v[a] = 1;
	Q.push(a);
	int cnt = 0;
	while(!Q.empty()) {
		int q_size = Q.size();
		for(int i = 0; i < q_size; i++) {
			for(int a : r[Q.front()]) {
				if (a == b) {
					cout << cnt+1 << endl;
					return 0;
				}
				else if (v[a] != 1) {
					v[a] = 1;
					Q.push(a);
				}
			}
			Q.pop();
		}
		cnt++;
	}
	cout << "-1" << endl;
	return 0;
}