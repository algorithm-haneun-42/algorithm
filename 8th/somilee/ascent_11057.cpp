#include <iostream>

using namespace std;

int n;
int d[10][1005];

int main()
{
	cin >> n;
	
	for(int i = 0; i < 10; i++)
		d[i][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[0][i] = 1;
		for (int j = 1; j <= 9; j++)
			d[j][i] = (d[j-1][i] + d[j][i-1]) % 10007;
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + d[i][n]) % 10007;
	cout << sum;
}