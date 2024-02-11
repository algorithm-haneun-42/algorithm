
#include <iostream>
#include <queue>

int	island[101][101];
int	da[4] = {0, 0, 1, -1};
int	db[4] = {1, -1, 0, 0};

int	main(void)
{
	int	n;

	std::cin >> n;
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++)
			std::cin >> island[a][b];

	std::queue < std::pair < int, int > >	que;
	int	number = 1;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			if (island[a][b] == 1)
			{
				number++;
				island[a][b] = number;
				que.push(std::make_pair(a, b));
			}
			while (!que.empty())
			{
				int	ca = que.front().first;
				int	cb = que.front().second;
				que.pop();
				for (int i = 0; i < 4; i++)
				{
					int	na = ca + da[i];
					int	nb = cb + db[i];
					if (na < 0 || nb < 0 || na >= n || nb >= n)
						continue ;
					if (island[na][nb] == 1)
					{
						island[na][nb] = number;
						que.push(std::make_pair(na, nb));
					}
				}
			}
		}
	}
	int	min = -2147483648;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			std::queue < std::pair < int, std::pair < int, int > > >	que2;
			if (island[a][b] > 0)
				que2.push(std::make_pair(0, std::make_pair(a, b)));
			while (!que2.empty())
			{
				int	bridge = que2.front().first;
				int	ca = que2.front().second.first;
				int	cb = que2.front().second.second;
				que2.pop();
				for (int i = 0; i < 4; i++)
				{
					int	na = ca + da[i];
					int	nb = cb + db[i];
					if (na < 0 || nb < 0 || na >= n || nb >= n)
						continue ;
					if (island[na][nb] > 0 && island[na][nb] != island[a][b])
					{
						if (min < bridge)
							min = bridge;
						continue ;
					}
					if (island[na][nb] == 0)
					{
						island[na][nb] = bridge - 1;
						que2.push(std::make_pair(bridge - 1, std::make_pair(na, nb)));
					}
					else if (island[na][nb] < 0 && bridge - 1 > island[na][nb])
					{
						island[na][nb] = bridge - 1;
						que2.push(std::make_pair(bridge - 1, std::make_pair(na, nb)));
					}
				}
			}
		}
	}
	std::cout << min * -1 << std::endl;
}
