#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int b[101][100001];
vector<pair<int, int> > V;
int main(void) {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int w, v; cin >> w >> v;
		V.push_back({w, v});
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++ ) {
			int cur_weight = V[i-1].first;
			int cur_val = V[i-1].second;
			if(cur_weight <= j)
				b[i][j] = max(b[i-1][j], b[i-1][j - cur_weight] + cur_val);
			else
				b[i][j] = b[i-1][j];
		}
	}
	cout << b[n][k];
}