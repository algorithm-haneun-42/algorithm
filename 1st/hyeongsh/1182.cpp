#include <iostream>

void	recur_ans(int deep, int sum, int n, int s, int *ans, int *num);

int	main(void)
{
	int	n, s, ans, num[20];

	ans = 0;
	std::cin >> n >> s;
	for (int i = 0; i < n; i++)
		std::cin >> num[i];
	recur_ans(0, 0, n, s, &ans, num);
	std::cout << ans << std::endl;
}

void	recur_ans(int deep, int sum, int n, int s, int *ans, int *num)
{
	if (deep == n)
		return ;
	for (int i = deep; i < n; i++)
	{
		sum += num[deep];
		if (sum == s)
			(*ans)++;
		if (deep < n)
			recur_ans(deep + 1, sum, n, s, ans, num);
		sum -= num[deep++];
	}
}