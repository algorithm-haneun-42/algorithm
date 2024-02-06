
#include <iostream>
#include <queue>
#include <cstring>

int area[300][300];
int da[4] = {0, 0, 1, -1};
int db[4] = {1, -1, 0, 0};

int main(void)
{
    int n, m;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::queue< std::pair< int, int > >  que;

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> area[i][j];
    int year = 0;
    while (42)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < m; b++)
            {
                if (area[a][b] == 0)
                    que.push(std::make_pair(a, b));
            }
        }
        while (!que.empty())
        {
            int ca = que.front().first;
            int cb = que.front().second;

            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int na = ca + da[i];
                int nb = cb + db[i];
                if (na < 0 || na >= n || nb < 0 || nb >= m)
                    continue ;
                if (area[na][nb] > 0)
                    area[na][nb]--;
            }
        }
        int vis[300][300];
        int num = 0;
        memset(vis, 0, sizeof(vis));
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < m; b++)
            {
                if (area[a][b] > 0 && vis[a][b] == 0)
                {
                    vis[a][b] = 1;
                    num++;
                    que.push(std::make_pair(a, b));
                }
                while (!que.empty())
                {
                    int ca = que.front().first;
                    int cb = que.front().second;

                    que.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int na = ca + da[i];
                        int nb = cb + db[i];
                        if (na < 0 || na >= n || nb < 0 || nb >= m)
                            continue ;
                        if (area[na][nb] > 0 && vis[na][nb] == 0)
                        {
                            vis[na][nb] = 1;
                            que.push(std::make_pair(na, nb));
                        }
                    }
                }
            }
        }
        year++;
        if (num > 1)
            break ;
        if (num == 0)
        {
            year = 0;
            break ;
        }
    }
    std::cout << year << std::endl;
}

