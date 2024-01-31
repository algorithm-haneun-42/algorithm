
#include <iostream>
#include <queue>
#include <cstring>

void	print_map(int map[301][301]);
int		bfs(int my_map[301][301], int a, int b, int map_size);

int	main(void)
{
	int	t;

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int	my_map[301][301];
		int	map_size;
		int	cur_a;
		int	cur_b;
		int	pos_a;
		int	pos_b;
		int ans = 0;

		memset(my_map, 0, sizeof(my_map));

		std::cin >> map_size;
		std::cin >> cur_a >> cur_b;
		std::cin >> pos_a >> pos_b;
		my_map[pos_a][pos_b] = -1;
		ans = bfs(my_map, cur_a, cur_b, map_size);
		std::cout << ans << std::endl;
	}
}

int	bfs(int my_map[301][301], int a, int b, int map_size)
{
	std::queue< std::pair<int, int> >	q;
	int	da[8] = {1, -1, 1, -1, 2, 2, -2, -2};
	int	db[8] = {2, 2, -2, -2, 1, -1, 1, -1};
	if (my_map[a][b] == -1)
		return (0);
	q.push(std::make_pair(a, b));
	while (!q.empty())
	{
		int	tmp_a = q.front().first;
		int	tmp_b = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int	na = tmp_a + da[i];
			int	nb = tmp_b + db[i];
			if (na < 0 || na >= map_size || nb < 0 || nb >= map_size)
				continue ;
			if (my_map[na][nb] == -1)
				return (my_map[tmp_a][tmp_b] + 1);
			if (my_map[na][nb] != 0)
				continue ;
			my_map[na][nb] = my_map[tmp_a][tmp_b] + 1;
			q.push(std::make_pair(na, nb));
		}
	}
	return (0);
}

void	print_map(int map[301][301])
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			std::cout << map[i][j] << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
