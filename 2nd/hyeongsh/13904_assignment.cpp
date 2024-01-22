
#include <iostream>
#include <algorithm>
#include <vector>

bool	pair_compare(const std::pair<int, int>& a, const std::pair<int, int>& b);

int	main(void)
{
	int	n;
	int	ans = 0;
	int	deadline;
	
	std::cin >> n;

	std::vector<std::pair<int, int> >	assign(n);
	for (int i = 0; i < n; i++)
		std::cin >> assign[i].first >> assign[i].second;
	std::sort(assign.begin(), assign.end(), pair_compare);
	deadline = assign[0].first;
	for (int i = deadline; i > 0; i--)
	{
		int	max = 0;
		int	max_index = -1;
		for (int j = 0; j < n; j++)
		{
			if (assign[j].first < i)
				continue ;
			if (max < assign[j].second)
			{
				max = assign[j].second;
				max_index = j;
			}
		}
		if (max != 0)
		{
			assign[max_index].second = -1;
			ans += max;
		}
	}
	std::cout << ans << std::endl;
}

bool	pair_compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.first > b.first)
		return (1);
	else if (a.first == b.first && a.second > b.second)
		return (1);
	return (0);
}
