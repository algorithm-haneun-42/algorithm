#include <iostream>
#include <cmath>

using namespace std;

// 10 10 8 8 10 10 인 경우
void print_score(int score[10010][3], int n)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= n + 1; j++)
		{
			cout << score[j][i] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int n;
	int cup[10010];
	int score[10010][3];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cup[i];
	cup[n + 1] = 0;
	score[1][0] = 0;
	score[1][1] = cup[1];
	score[1][2] = cup[1];
	score[2][0] = cup[1];
	score[2][1] = cup[2];
	score[2][2] = cup[1] + cup[2];
	if (n <= 2)
	{
		cout << max(score[n][1], score[n][2]) << endl;
		return (0);
	}
	for (int i = 3; i <= n + 2; i++)
	{
		if (k >= 4)
			score[i][0] = max(score[i - 1][0], max(score[i - 1][1], score[i - 1][2]));
		score[i][1] = max(score[i - 2][1], score[i - 2][2]) + cup[i];
		score[i][2] = score[i - 1][1] + cup[i];
	}
	print_score(score, n);
	cout << max(score[n + 1][0], max(score[n + 1][1], score[n + 1][2])) << endl;
	return (0);
}
