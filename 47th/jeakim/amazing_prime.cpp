#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

enum TRUE
{
	TRUE,
	FALSE
};

int	max;

void	init_prime(int prm[], int n)
{
	prm[0] = FALSE;
	prm[1] = FALSE;
	for (int i = 2; i < n; i++)
		prm[i] = TRUE;
	for (int i = 2; i <= n; i++)
	{
		if (prm[i] == 0) {
			for (int j = i * 2; j <= n; j += i)
				prm[j] = FALSE;
		}
	}
}

int main()
{
	int n;
	int max;

	cin >> n;
	max = pow(10, n);
	
	int prm[max];
	init_prime(prm, pow(10, n));
	for (int i = pow(10, n - 1); i < pow(10, n); i++)
	{
		int num = i;
		int flag = 0;
		for (int j = 0; j < n && flag == 0; j++)
		{
			if (num == 0 || num == 1 || prm[num] == FALSE)
				flag = 1;
			num /= 10;
		}
		if (flag == 0)
			cout << i << endl;
	}
	return (0);
}