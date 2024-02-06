
#include <iostream>
#include <queue>
#include <algorithm>

int	buf[25][25];
int	home_num[625];
int	da[4] = {0, 1, 0, -1};
int	db[4] = {1, 0, -1, 0};

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int	n;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	tmp;

		std::cin >> tmp;
		for (int j = 0; j < n; j++)
			buf[i][j] = tmp[j] - '0';
	}
	int	num = 1;
	std::queue< std::pair< int, int > >	que;

	for (int a = 0; a < n; a++)
	{
		for (int b = 0 ; b < n; b++)
		{
			if (buf[a][b] == 1)
			{
				buf[a][b] = ++num;
				home_num[num]++;
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
					if (na < 0 || na >= n || nb < 0 || nb >= n)
						continue ;
					if (buf[na][nb] == 1)
					{
						buf[na][nb] = num;
						home_num[num]++;
						que.push(std::make_pair(na, nb));
					}
				}
			}
		}
	}
	std::sort(home_num, home_num + 625);
	std::cout << num - 1 << std::endl;
	for (int i = 0; i < 625; i++)
	{
		if (home_num[i] == 0)
			continue ;
		std::cout << home_num[i] << std::endl;
	}
}
