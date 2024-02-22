
#include <iostream>

int	narr[30001];

int	main(void)
{
	int	n, d, k, c;

	std::cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)
		std::cin >> narr[i];
	int	*st = narr;
	int	min = 2147483647;
	int	max = -2147483648;
	while (st - narr < n)
	{
		int	*en = st;
		int	karr[3001] = {0,};
		int	dup = 0;
		for (int i = 0; i <= k; i++)
		{
			if (en - narr >= n)
				en = en - n;
			if (i == k)
			{
				if (min > dup)
					min = dup;
				if (max < k - min + (karr[c] == 0))	
					max = k - min + (karr[c] == 0);
				break ;
			}
			if (karr[*en] == 0)
				karr[*en] = 1;
			else
				dup++;
			if (dup > min)
				break ;
			en++;
		}
		st++;
	}
	std::cout << max << std::endl;
}
