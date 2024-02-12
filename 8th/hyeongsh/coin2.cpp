
#include <iostream>
#include <queue>

int	coin[101];
int	price[10001];

int	main(void)
{
	int	n, k;
	std::queue < std::pair < int, int > >	que;

	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		std::cin >> coin[i];
		if (coin[i] > 10000)
			continue ;
		price[coin[i]] = 1;
		que.push(std::make_pair(coin[i], 1));
	}
	while (!que.empty())
	{
		int	c_price = que.front().first;
		int	c_coin = que.front().second;

		if (c_price == k)
		{
			std::cout << c_coin << std::endl;
			return (0);
		}
		que.pop();
		for (int i = 0; i < n; i++)
		{
			int	n_price = c_price + coin[i];
			int	n_coin = c_coin + 1;
			if (n_price == k)
			{
				std::cout << n_coin << std::endl;
				return (0);
			}
			else if (n_price > k)
				continue ;
			else if (price[n_price] == 0)
			{
				price[n_price] = 1;
				que.push(std::make_pair(n_price, n_coin));
			}
		}
	}
	std::cout << -1 << std::endl;
	return (0);
}
