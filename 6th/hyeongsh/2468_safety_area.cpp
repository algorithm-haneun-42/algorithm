
#include <iostream>
#include <queue>
#include <cstring>

int	area[100][100];
int	da[4] = {0, 0, 1, -1};
int	db[4] = {1, -1, 0, 0};

int	main(void)
{
	int	n;
	int	ans = 0;

	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> area[i][j];
	for (int h = 0; h < 100; h++)
	{
		int	vis[100][100];
		memset(vis, 0, sizeof(vis));
		int	num = 0;
		std::queue< std::pair< int, int > >	que;
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (area[a][b] > h && vis[a][b] == 0)
				{
					vis[a][b] = 1;
					num++;
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
						if (area[na][nb] > h && vis[na][nb] == 0)
						{
							vis[na][nb] = 1;
							que.push(std::make_pair(na, nb));
						}
					}
				}
			}
		}
		if (num > ans)
			ans = num;
	}
	std::cout << ans << std::endl;
}
