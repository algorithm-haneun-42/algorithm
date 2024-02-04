
#include <iostream>
#include <queue>

int chess[200][200];
int vis[200][200][2];
int da[12] = {0, 0, 1, -1, 1, -1, 1, -1, 2, 2, -2, -2};
int db[12] = {1, -1, 0, 0, 2, 2, -2, -2, 1, -1, 1, -1};

int main(void)
{
    int k;
    int w, h;

    std::cin >> k;
    std::cin >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            std::cin >> chess[i][j];
    if (w == 1 && h == 1)
    {
        if (chess[0][0] == 0)
            std::cout << 0 << std::endl;
        else
            std::cout << -1 << std::endl;
        return (0);
    }
    std::queue< std::pair < std::pair< int, int >, std::pair < int, int > > > que;
    que.push(std::make_pair(std::make_pair(0, 0), std::make_pair(0, 0)));
    vis[0][0][0] = 1;
    vis[0][0][1] = 0;
    while (!que.empty())
    {
        int knight = que.front().first.first;
        int move = que.front().first.second;
        int ca = que.front().second.first;
        int cb = que.front().second.second;

        que.pop();
        for (int i = 0; i < 12; i++)
        {
            int na = ca + da[i];
            int nb = cb + db[i];
            if (i > 3 && knight >= k)
                continue ;
            if (na < 0 || nb < 0 || na >= h || nb >= w)
                continue ;
            if (na == h - 1 && nb == w - 1)
            {
                std::cout << move + 1 << std::endl;
                return (0);
            }
            if (chess[na][nb] == 0)
            {
                int monkey = (i > 3);

                if (vis[na][nb][0] == 0 && vis[na][nb][1] == 0)
                {
                    vis[na][nb][0] = 1;
                    vis[na][nb][1] = knight + monkey;
                    que.push(std::make_pair(std::make_pair(knight + monkey, move + 1), std::make_pair(na, nb)));
                }
                else if (vis[na][nb][1] > knight + monkey)
                {
                    vis[na][nb][1] = knight + monkey;
                    que.push(std::make_pair(std::make_pair(knight + monkey, move + 1), std::make_pair(na, nb)));
                }
            }
        }
    }
    std::cout << -1 << std::endl;
    return (0);
}
