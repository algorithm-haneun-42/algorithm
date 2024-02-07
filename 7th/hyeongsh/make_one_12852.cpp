
#include <iostream>

int	main(void)
{
	int	n;
	int	arr[1000002];
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	
	std::cin >> n;
	for (int i = 4; i <= n; i++)
	{
		int	one = 2147483647;
		int	two = 2147483647;
		int	three = 2147483647;

		if (i % 3 == 0)
			three = arr[i / 3];
		if (i % 2 == 0)
			two = arr[i / 2];
		one = arr[i - 1];
		if (one < two && one < three)
			 arr[i] = one + 1;
		if (two <= one && two < three)
			 arr[i] = two + 1;
		if (three <= one && three <= two)
			 arr[i] = three + 1;
	}
	std::cout << arr[n] << std::endl;
	while (n != 1)
	{
		int	one = 2147483647;
		int	two = 2147483647;
		int	three = 2147483647;

		std::cout << n << ' ';
		if (n % 3 == 0)
			three = arr[n / 3];
		if (n % 2 == 0)
			two = arr[n / 2];
		one = arr[n - 1];
		if (one < two && one < three)
			n = n - 1;
		if (two <= one && two < three)
			n = n / 2;
		if (three <= one && three <= two)
			n = n / 3;
	}
	std::cout << n << std::endl;
}
