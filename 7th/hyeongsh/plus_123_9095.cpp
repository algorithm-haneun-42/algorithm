
#include <iostream>

int	main(void)
{
	int	t;
	int	arr[11];

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int	n;
		std::cin >> n;
		std::cout << arr[n] << std::endl;
	}
	return (0);
}
