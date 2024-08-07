#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[201];
int dp[201];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << N - *max_element(dp + 1, dp + N + 1) << '\n';
	return 0;
}