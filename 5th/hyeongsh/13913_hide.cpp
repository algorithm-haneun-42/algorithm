
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

#define INIT_VALUE -1

int	pos[100001];
int	da[3] = {1, -1, 2};

int	main(void)
{
	int	n, k;

	std::cin >> n >> k;
	std::queue< int >	que;

	std::fill(pos, pos + 100001, INIT_VALUE);
	if (n == k)
	{
		std::cout << 0 << std::endl << k << std::endl;
		return (0);
	}
	que.push(n);
	pos[n] = -2;
	while (!que.empty())
	{
		int	cur = que.front();
		
		que.pop();
		for (int i = 0; i < 3; i++)
		{
			int	na;
			
			if (i == 2)
				na = cur * da[i];
			else
				na = cur + da[i];
			if (na < 0 || na > 100000)
				continue ;
			if (na == k)
			{
				pos[na] = cur;
				break ;
			}
			if (pos[na] == INIT_VALUE)
			{
				pos[na] = cur;
				que.push(na);
			}
		}
		if (pos[k] != INIT_VALUE)
			break ;
	}
	std::stack<int>	ans;
	

	int	tmp = k;
	
	ans.push(tmp);
	while (pos[tmp] != -2)
	{
		tmp = pos[tmp];
		ans.push(tmp);
	}
	std::cout << ans.size() - 1 << std::endl;
	while (!ans.empty())
	{
		int	print = ans.top();
		ans.pop();
		if (ans.empty())
			std::cout << print << std::endl;
		else
			std::cout << print << " ";
	}
	return (0);
}
