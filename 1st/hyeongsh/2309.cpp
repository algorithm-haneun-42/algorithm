#include <iostream>
#include <algorithm>

int	main(void)
{
	int	seven[7];
	int	small[9];
	int	sum = 0;

	for (int i = 0; i < 9; i++)
	{
		std::cin >> small[i];
		sum += small[i];
	}
	std::sort(small, small + 9);

	for (int i = 0; i < 9; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if (small[i] + small[j] == sum - 100)
			{
				small[i] = -1;
				small[j] = -1;
				break ;
			}
		}
		if (small[i] == -1)
			break ;
	}
	for (int i = 0; i < 9; i++)
	{
		if (small[i] != -1)
			std::cout << small[i] << std::endl;
	}
}
