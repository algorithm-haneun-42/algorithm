
#include <iostream>
#include <queue>

int	box[100][100][100];
int	da[6] = {0, 0, 1, 0, 0, -1};
int	db[6] = {0, 1, 0, 0, -1, 0};
int	dc[6] = {1, 0, 0, -1, 0, 0};

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int	m, n, h;
	int	ans = 0;
	std::cin >> m >> n >> h;

	std::queue< std::pair< int, std::pair< int, int > > >	q;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				std::cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					q.push(std::make_pair(i, std::make_pair(j, k)));
			}
		}
	}
	while (!q.empty())
	{
		int	a = q.front().first;
		int	b = q.front().second.first;
		int	c = q.front().second.second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int	na = a + da[i];
			int	nb = b + db[i];
			int	nc = c + dc[i];
			if (na < 0 || na >= h || nb < 0 || nb >= n || nc < 0 || nc >= m)
				continue ;
			if (box[na][nb][nc] == 0)
			{
				box[na][nb][nc] = box[a][b][c] + 1;
				q.push(std::make_pair(na, std::make_pair(nb, nc)));
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					std::cout << -1 << std::endl;
					return (0);
				}
				else if (box[i][j][k] > ans)
					ans = box[i][j][k];
			}
		}
	}
	std::cout << ans - 1 << std::endl;
	return (0);
}
