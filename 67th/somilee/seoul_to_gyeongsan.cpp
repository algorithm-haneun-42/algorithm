#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, t1, m1, t2, m2, t, m;
int b[101][100001];
vector<pair<int, int> > v;
int main(void) {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> t1 >> m1 >> t2 >> m2;
		if(t1 > t2) {
			t += t2;
			m += m2;
			v.push_back({t1 - t2, m1 - m2});
		}
		else {
			t += t1;
			m += m1;
			v.push_back({t2 - t1, m2 - m1});
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k - t; j++) {
			int cur_t = v[i-1].first;
			int cur_m = v[i-1].second;
			if(cur_t <= j)
				b[i][j] = max(b[i-1][j], b[i-1][j-cur_t] + cur_m);
			else
				b[i][j] = b[i-1][j];
		}
	}
	cout << b[n][k-t]+m << endl;
}