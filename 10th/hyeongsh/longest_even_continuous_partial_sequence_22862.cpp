
#include <iostream>

int	arr[1000001];

int	main(void)
{
	int	s, k;
	std::cin >> s >> k;
	for (int i = 0; i < s; i++)
		std::cin >> arr[i];
	int	*st = arr;
	int	*en = arr;
	int	del = 0;
	int	max = -1;
	while (*st != 0)
	{
		while (*en != 0)
		{
			if (*en % 2 == 1 && del < k)
				del++;
			else if (*en % 2 == 1)
				break ;
			en++;
		}
		//std::cout << "st: " << st - arr << "  en: " << en - arr << std::endl;
		if (max < en - st - del)
			max = en - st - del;
		if (*st % 2 == 1)
			del--;
		st++;
	}
	std::cout << max << std::endl;
}
