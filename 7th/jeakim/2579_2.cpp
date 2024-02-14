#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int stair[301];
	int score[301];
	int n;
	int total;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
		total += stair[i];
	}
	score[1] = stair[1];
	score[2] = stair[2];
	score[3] = stair[3];
	for (int i = 4; i <= n; i++)
		score[i] = min(score[i - 2], score[i - 3]) + stair[i];
	cout << total - min(score[n - 1], score[n - 2]) << endl;

	return (0);
}