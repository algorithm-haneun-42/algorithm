
#include <iostream>

int	dp[32];

int	main(void)
{
	int	n;

	std::cin >> n;
	dp[2] = 3;
	for	(int i = 4; i < 31; i++)
	{
		if (i % 2 == 1)
			continue ;
		int	sum = dp[i - 2] * 3 + 2;
		for (int j = 2; j < i - 2; j++)
		{
			if (j % 2 == 1)
				continue ;
			sum += dp[j] * 2;
		}
		dp[i] = sum;
	}
	std::cout << dp[n] << std::endl;
}
