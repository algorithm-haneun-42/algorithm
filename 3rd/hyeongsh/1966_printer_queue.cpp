
#include <iostream>
#include <queue>

int	main(void)
{
	int	t;

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int	n;
		int	m;
		int	count = 0;
		std::queue<int>	que;
		int	priority[10] = {0, };

		std::cin >> n >> m;

		int	paper;
		for (int j = 0; j < n; j++)
		{
			std::cin >> paper;
			que.push(paper);
			priority[paper]++;
		}
		while (42)
		{
			int	max;

			for (int i = 9; i > 0; i--)
			{
				if (priority[i] != 0)
				{
					max = i;
					break ;
				}
			}
			if (que.front() >= max)
			{
				count++;
				if (m == 0)
				{
					std::cout << count << std::endl;
					break ;
				}
				que.pop();
				priority[max]--;
				m--;
			}
			else
			{
				int	k = que.front();
				if (m == 0)
					m = que.size() - 1;
				else
					m--;
				que.pop();
				que.push(k);
			}
		}
	}
}
