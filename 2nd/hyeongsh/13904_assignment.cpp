
#include <iostream>
#include <algorithm>
#include <vector>

bool	pair_compare(const std::pair<int, int>& a, const std::pair<int, int>& b);

int	main(void)
{
	int	n;
	int	max = 0;
	
	std::cin >> n;

	std::vector<std::pair<int, int> >	assign(n);
	for (int i = 0; i < n; i++)
		std::cin >> assign[i].first >> assign[i].second;
	std::sort(assign.begin(), assign.end(), pair_compare);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (assign[i].first == assign[i + 1].first)
			
		}
	}
	std::cout << max << std::endl;
}

bool	pair_compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.first < b.first)
		return (1);
	else if (a.first == b.first && a.second > b.second)
		return (1);
	return (0);
}
