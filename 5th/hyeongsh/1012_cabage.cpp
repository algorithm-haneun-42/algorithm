
#include <iostream>
#include <queue>

int	bfs(int a, int b, int map[51][51]);
void	print_map(int map[51][51]);

int	main(void)
{
	int	t;

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		int	map[51][51] = {{0}};
		int	garo;
		int	sero;
		int	cabage;
		int ans = 0;

		std::cin >> garo >> sero >> cabage;
		for (int j = 0; j < cabage; j++)
		{
			int	a, b;

			std::cin >> b >> a;
			map[a][b] = 1;
		}
		for (int a = 0; a < sero; a++)
		{
			for (int b = 0; b < garo; b++)
			{
				if (bfs(a, b, map) == 1)
					ans++;
			}
		}
		std::cout << ans << std::endl;
	}
}

int	bfs(int a, int b, int map[51][51])
{
	if (map[a][b] == 0 || map[a][b] == 2)
		return (0);
	
	std::queue< std::pair<int, int> >	q;
	int	da[4] = {1, 0, -1, 0};
	int	db[4] = {0, 1, 0, -1};
	q.push(std::make_pair(a, b));
	map[a][b] = 2;
	while (42)
	{
		if (q.size() == 0)
			break ;
		int	tmp_a = q.front().first;
		int	tmp_b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	na = tmp_a + da[i];
			int	nb = tmp_b + db[i];
			if (na < 0 || na >= 50 || nb < 0 || nb >= 50)
				continue ;
			if (map[na][nb] == 1)
			{
				map[na][nb] = 2;
				q.push(std::make_pair(na, nb));
			}
		}
	}
	return (1);
}
