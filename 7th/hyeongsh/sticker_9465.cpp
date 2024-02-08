
#include <iostream>
#include <algorithm>

int	main(void)
{
	int	t, n;

	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		int	**sticker = new int *[2];
		sticker[0] = new int[n + 2];
		sticker[1] = new int[n + 2];
		sticker[0][0] = 0;
		sticker[0][1] = 0;
		sticker[1][0] = 0;
		sticker[1][1] = 0;
		for (int a = 0; a < 2; a++)
			for (int b = 2; b < n + 2; b++)
				std::cin >> sticker[a][b];
		for (int b = 2; b < n + 2; b++)
		{
			for (int a = 0; a < 2; a++)
			{
				sticker[a][b] += std::max(sticker[a * -1 + 1][b - 1],
					sticker[a * -1 + 1][b - 2]);
			}
		}
		std::cout << std::max(sticker[0][n + 1], sticker[1][n + 1]) << std::endl;
	}
}
