
#include <iostream>
#include <queue>
#include <vector>

int	main(void)
{
	int	n, k;
	std::queue<int>		fri;
	std::vector<int>	bf;
	int	ans = 0;

	std::ios::sync_with_stdio(false); 
	std::cin.tie(NULL);
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		std::string	name;
		int			size;
		
		std::cin >> name;
		size = name.size();
		fri.push(size);
	}
	for (int i = 0; i < k; i++)
	{
		bf.push_back(fri.front());
		fri.pop();
	}
	for (int i = 0; i < n; i++)
	{
		if (fri.size() != 0)
		{
			bf.push_back(fri.front());
			fri.pop();
		}
		for (int j = 1; j < bf.size(); j++)
		{
			if (bf[0] == bf[j])
				ans++;
		}
		bf.erase(bf.begin());
	}
	std::cout << ans << std::endl;
}
