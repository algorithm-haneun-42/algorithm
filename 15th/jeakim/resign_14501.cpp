#include <iostream>

using namespace std;

int count_benefit(int n, int schedule[16][2], int benefit[16])
{
	int dp[16];
	int max_point;

	for (int i = 0; i < n; i++){
		
	}
}

int main()
{
	int n;
	int schedule[16][2];
	int benefit[16] = {0};

	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> schedule[i][0] >> schedule[i][1];
	
	cout << count_benefit(n, schedule, benefit) << '\n';
	return (0);
}