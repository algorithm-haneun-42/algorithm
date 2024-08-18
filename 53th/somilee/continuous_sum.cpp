#include <iostream>
#include <algorithm>

using namespace std;

int n;
int num[100005];
int sum[2][100005];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> num[i];
	int ans = -1001;
	for(int i = 1; i <= n; i++) {
		if (num[i] < 0) {
			ans = max(ans, max(sum[0][i-1], sum[1][i-1]));
			sum[0][i] = max(0, max(sum[0][i-1], sum[1][i-1]) + num[i]);
			sum[1][i] = sum[0][i-1];
		}
		else {
			sum[0][i] = sum[0][i-1] + num[i];
			sum[1][i] = sum[1][i-1] + num[i];
		}
	}
	sort(num, num+n+1);
	if (num[n-1] < 0) {
		cout << num[n-1] << endl;
		return 0;
	}
	cout << max(ans, max(sum[0][n], sum[1][n])) << endl;
	return 0;
}
