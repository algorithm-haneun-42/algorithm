
#include <iostream>
#include <queue>

int area[1000][1000];
int vis[1000][1000];
int wall[1000][1000];
int da[4] = {0, 0, 1, -1};
int db[4] = {1, -1, 0, 0};

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::queue< std::pair < std::pair < int, int >, std::pair < int, int > > >   que;
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::string toss;

        std::cin >> toss;
        for (int j = 0; j < m; j++)
            area[i][j] = toss[j] - '0';
    }
    if (n == 1 && m == 1)
    {
        std::cout << 1 << std::endl;
        return (0);
    }
    vis[0][0] = 1;
    que.push(std::make_pair(std::make_pair(0, 1), std::make_pair(0, 0)));
    while (!que.empty())
    {
        int use = que.front().first.first;
        int walk = que.front().first.second;
        int ca = que.front().second.first;
        int cb = que.front().second.second;

        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int na = ca + da[i];
            int nb = cb + db[i];
            if (na < 0 || na >= n || nb < 0 || nb >= m)
                continue ;
            if (na == n - 1 && nb == m - 1)
            {
                std::cout << walk + 1 << std::endl;
                return (0);
            }
            if (vis[na][nb] == 0 && area[na][nb] == 0)
            {
                vis[na][nb] = 1;
                wall[na][nb] = use;
                que.push(std::make_pair(std::make_pair(use, walk + 1), std::make_pair(na, nb)));
            }
            else if (vis[na][nb] == 1 && area[na][nb] == 0 && wall[na][nb] > use)
            {
                wall[na][nb] = 0;
                que.push(std::make_pair(std::make_pair(use, walk + 1), std::make_pair(na, nb)));
            }
            else if (area[na][nb] == 1 && use == 0)
            {
                vis[na][nb] = 1;
                wall[na][nb] = use + 1;
                que.push(std::make_pair(std::make_pair(use + 1, walk + 1), std::make_pair(na, nb)));
            }
        }
    }
    std::cout << -1 << std::endl;
    return (0);
}
