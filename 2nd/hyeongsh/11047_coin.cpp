
#include <iostream>

int	main(void)
{
	int	N;
	int	K;
	int	*arr;
	int	max = -1;
	int	ans = 0;

	std::cin >> N >> K;
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		if (arr[i] <= K)
			max = i;
	}
	while (K)
	{
		if (K - arr[max] >= 0)
		{
			K -= arr[max];
			ans++;
			continue ;
		}
		max--;
	}
	std::cout << ans << std::endl;
	delete[] arr;
}
