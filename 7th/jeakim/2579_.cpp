#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int stair[301];
	int score[301][3];
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> stair[i];
	score[1][1] = stair[1];
	score[1][2] = 0;
	score[2][1] = stair[2];
	score[2][2] = stair[1] + stair[2];
	for (int i = 3; i <= N; i++)
	{
		score[i][1] = max(score[i - 2][1], score[i - 2][2]) + stair[i];
		score[i][2] = score[i - 1][1] + stair[i];
	}

	cout << max(score[N][1], score[N][2]) << endl;
	return (0);
}
