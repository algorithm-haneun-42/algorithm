#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int cup[10002];
	int score[10001][3];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cup[i];
	cup[n + 1] = 0;
	score[1][1] = cup[1];
	score[1][2] = cup[1];
	score[2][1] = cup[2];
	score[2][2] = cup[1] + cup[2];
	if (n <= 2)
	{
		cout << max(score[n][1], score[n][2]) << endl;
		return (0);
	}
	for (int i = 3; i <= n + 1; i++)
	{
		score[i][1] = max(score[i - 2][1], score[i - 2][2]) + cup[i];
		score[i][2] = score[i - 1][1] + cup[i];
	}
	cout << max(score[n + 1][1], score[n + 1][2]) << endl;
	return (0);
}
