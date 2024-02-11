
#include <iostream>
#include <algorithm>

int	dp[1005][1005];

int	main(void)
{
	std::string	str1;
	std::string	str2;

	std::cin >> str1 >> str2;
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	std::cout << dp[str1.size()][str2.size()] << std::endl;
	return (0);
}
