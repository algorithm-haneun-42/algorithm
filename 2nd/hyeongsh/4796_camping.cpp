
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int>	cooltime;
	std::vector<int>	max;
	std::vector<int>	vacation;
	int	in;
	int	i = 0;
	int	ans;

	while (42)
	{
		std::cin >> in;
		max.push_back(in);
		std::cin >> in;
		cooltime.push_back(in);
		std::cin >> in;
		vacation.push_back(in);
		if (max[i] == 0 && cooltime[i] == 0 && vacation[i] == 0)
			break ;
		i++;
	}
	i = 0;
	while (42)
	{
		if (max[i] == 0 && cooltime[i] == 0 && vacation[i] == 0)
			break ;
		while (vacation[i])
		{
			if (vacation[i] - max[i] >= 0)
				ans += max[i];
			else
				ans += vacation[i];
			if (vacation[i] - cooltime[i] < 0)
				vacation[i] = 0;
			else
				vacation[i] -= cooltime[i];
		}
		std::cout << "Case " << i + 1 << ": " << ans << std::endl;
		ans = 0;
		i++;
	}
	return (0);
}
