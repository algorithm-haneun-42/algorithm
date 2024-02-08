#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i ++)
	{
		int n;
		cin >>n;

		int s[2][100000] = {0};
		for (int j = 0; j < 2; j ++)
			for(int k = 0; k < n; k ++)
				cin >> s[j][k];

		int b[3][100000] = {0};
		b[0][0] = s[0][0];
		b[1][0] = s[1][0];
		b[2][0] = 0;
		for (int j = 1; j < n; j ++)
		{
			b[0][j] = max(b[1][j-1] + s[0][j], b[2][j-1] + s[0][j]);
			b[1][j] = max(b[0][j-1] + s[1][j], b[2][j-1] + s[1][j]);
			b[2][j] = max(b[0][j-1] + 0, b[1][j-1] + 0);
		}	
		cout << max({b[0][n-1], b[1][n-1], b[2][n-1]}) << '\n';
	}
}


// 1: 50  40  200  140 250
// 2: 30  100 120  210 260
// x: 0   50  100  200 210