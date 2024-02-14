// https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void print_dp(int dp[1001][1001], int a, int b)
{
	for (int i = 0; i < a + 1; i++)
	{
		for (int j = 0; j < b + 1; j++)
			cout << dp[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	int dp[1001][1001];
	string a;
	string b;
	int cnt = 0;

	cin >> a >> b;
	for (int i = 0; i < a.size() + 1; i++)
	{
		for (int j = 0; j < b.size() + 1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	for (int i = 0; i < a.size() + 1; i++)
		for (int j = 0; j < b.size() + 1; j++)
			cnt = max(cnt, dp[i][j]);
	// print_dp(dp, a.size(), b.size());
	cout << cnt << endl;
	return (0);
}
