
#include "iostream"

int	arr[1000][10];

int	main(void)
{
	int	n;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i][9] = 1;
		for (int j = 8; j >= 0; j--)
		{
			int	y = arr[i][j + 1];
			int	x;
			if (i == 0)
				x = 0;
			else
				x = arr[i - 1][j];
			arr[i][j] = (x + y) % 10007;
		}
	}
	int	sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += (arr[n - 1][i]);
		sum = sum % 10007;
	}
	std::cout << sum << std::endl;
	return (0);
}
