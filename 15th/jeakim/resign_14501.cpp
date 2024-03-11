#include <iostream>
#include <cmath>

using namespace std;

void count_benefit(int n, int schedule[16][2], int dp[17])
{
	for (int i = n; i >= 0; i--){
		int pos = i + schedule[i][0];
		if (pos > n + 1)
			dp[i] = dp[i + 1]; //i일에 상담x
		else
			dp[i] = max(dp[i + 1], schedule[i][1] + dp[i + schedule[i][0]]);
	}
}

int main()
{
	int n;
	int schedule[16][2];
	int dp[17] = {0};
	int max_p = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> schedule[i][0] >> schedule[i][1];
	count_benefit(n, schedule, dp);
	for (int i = 1; i <= n; i++)
		max_p = max(max_p, dp[i]);
	cout << max_p << '\n';
	return (0);
}
