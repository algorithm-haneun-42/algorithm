
#include <iostream>
#include <vector>
#include <algorithm>

bool	pair_compare(const std::pair<int, int>& a, const std::pair<int, int>& b);

int	main(void)
{
	int	n;
	int	ans = 1;
	int	time;
	
	std::cin >> n;
	
	std::vector<std::pair<int, int> >	meet(n);
	for (int i = 0; i < n; i++)
		std::cin >> meet[i].first >> meet[i].second;
	std::sort(meet.begin(), meet.end(), pair_compare);
	time = meet[0].second;
	for (int i = 1; i < n; i++)
	{
		if (meet[i].first >= time)
		{
			ans++;
			time = meet[i].second;
		}
	}
	std::cout << ans << std::endl;
	return (0);
}

bool	pair_compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	if (a.second < b.second)
		return (1);
	else if (a.second == b.second && a.first < b.first)
		return (1);
	return (0);
}
