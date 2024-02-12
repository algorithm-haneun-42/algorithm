
#include <iostream>
#include <queue>

int	area[501][501];
int	dfs[501][501];
int	da[4] = {0, 1, 0, -1};
int	db[4] = {1, 0, -1, 0};
int	n, m;

int	dfs_recur(int ca, int cb);

int	main(void)
{
	std::cin >> m >> n;
	
	for (int a = 1; a <= m; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			std::cin >> area[a][b];
			dfs[a][b] = -1;
		}
	}
	dfs[m][n] = 1;
	std::cout << dfs_recur(1, 1) << std::endl;
	// std::cout << std::endl;
	// for (int a = 1; a <= m; a++)
	// {
	// 	for (int b = 1; b <= n; b++)
	// 	{
	// 		std::cout << dfs[a][b] << ' ';
	// 	}
	// 	std::cout << std::endl;
	// }
}

int	dfs_recur(int ca, int cb)
{
	int	tmp = 0;
	if (dfs[ca][cb] >= 0)
		return (dfs[ca][cb]);
	for (int i = 0; i < 4; i++)
	{
		int	na = ca + da[i];
		int	nb = cb + db[i];
		if (na <= 0 || nb <= 0 || na > m || nb > n)
			continue ;
		if (area[na][nb] < area[ca][cb])
			tmp += dfs_recur(na, nb);
	}
	dfs[ca][cb] = tmp;
	return (dfs[ca][cb]);
}
