
#include <iostream>

int	arr[200001];
int	check[100001];

int	main(void)
{
	int	n, k;

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	int	*st = arr;
	int	*en = st;
	int	max = -1;
	while (*st != 0)
	{
		if (arr + n - st < max)
			break ;
		while (42)
		{
			if (*en == 0)
			{
				if (en - st > max)
					max = en - st;
				std::cout << max << std::endl;
				return (0);
			}
			if (check[*en] < k)
				check[*en]++;
			else
			{
				if (en - st > max)
					max = en - st;
				break ;
			}
			en++;
		}
		check[*st]--;
		st++;
	}
	std::cout << max << std::endl;
	return (0);
}
