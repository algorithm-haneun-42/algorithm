
#include <iostream>

long long	dp[5000][2];

int	main(void)
{
	std::string	passwd;

	std::cin >> passwd;
	for (int i = 0; i < passwd.size(); i++)
	{
		if (passwd[i] < '0' || passwd[i] > '9')
		{
			std::cout << 0 << std::endl;
			return (0);
		}
		if (i == 0)
		{
			if (passwd[i] == '0')
			{
				std::cout << 0 << std::endl;
				return (0);
			}
			dp[i][0] = 1;
			dp[i][1] = 0;
			continue ;
		}
		int	word = (passwd[i - 1] - '0') * 10 + passwd[i] - '0';
		
		if (passwd[i] == '0')
		{
			if (word > 26)
			{
				std::cout << 0 << std::endl;
				return (0);
			}
			dp[i][0] = 0;
			dp[i][1] = dp[i - 1][0];
			continue ;
		}
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
		if (word > 26)
			dp[i][1] = 0;
		else
			dp[i][1] = dp[i - 1][0];
		std::cout << dp[i][0] << ' ' << dp[i][1] << std::endl;
	}
	std::cout << (dp[passwd.size() - 1][0] + dp[passwd.size() - 1][1]) % 1000000 << std::endl;
}
