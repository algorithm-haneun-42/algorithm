#include <iostream>
using namespace std;

int n;
int sum = 0;
int b[15][15];

int check_line (int k, int i)
{
	for(int j = 0; j < n; j++)
		if (b[k][j] == 1)
			return (1);
	for(int j = 0; j < n; j++)
		if (b[j][i] == 1)
			return (1);
	return (0);
}

int check_cross(int k, int i)
{
	for(int j = 1; j < 15; j++)
	{
		if (k-j >= 0 && k-j < n && i-j >= 0 && i-j < n)
			if (b[k-j][i-j] == 1)
				return (1);
		if (k-j >= 0 && k-j < n && i+j >= 0 && i+j < n)
			if (b[k-j][i+j] == 1)
				return (1);
		if (k+j >= 0 && k+j < n && i-j >= 0 && i-j < n)
			if (b[k+j][i-j] == 1)
				return (1);
		if (k+j >= 0 && k+j < n && i+j >= 0 && i+j < n)
			if (b[k+j][i+j] == 1)
				return (1);
	}
	return (0);
}

void n_queen(int k)
{
	if (k == n)
	{
		sum += 1;
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if(check_line(k, i) == 0 && check_cross(k, i) == 0)
		{
			b[k][i] = 1;
			n_queen(k+1);
			b[k][i] = 0;
		}
	}
}

int main(void)
{
	cin >> n;
	n_queen(0);
	cout << sum;
}