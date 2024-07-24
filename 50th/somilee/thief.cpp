#include <iostream>
#include <queue>

using namespace std;

int b[100005];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		for(int i = 0; i < n; i++)
			cin >> b[i];
		int sum = 0;
		int cnt = 0;
		for(int i = 0; i < m; i++)
			sum += b[i];
		if (sum < k)
			cnt++;
		for(int i = m; i < n+m-1; i++) {
			sum = sum - b[i-m] + b[i%n];
			if (sum < k)
				cnt++;
		}
		if (cnt != 0 && n == m)
			cnt = 1;
		cout << cnt << endl;
	}
}