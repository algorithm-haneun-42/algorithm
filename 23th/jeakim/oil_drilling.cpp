#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
map<int, int> oil_size;
int visit[501][501] = {0};

void find_oil(vector<vector<int> > land)
{
    queue<pair<int, int> > q;
    int cnt = 1;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (land[i][j] == 1 && visit[i][j] == 0){
                q.push({i, j});
                visit[i][j] = cnt;
                int oil = 0;
                while (!q.empty()){
                    pair<int, int> cur;
                    cur = q.front();
                    q.pop();
                    visit[cur.first][cur.second] = cnt;
                    oil++;
                    for (int k = 0; k < 4; k++){
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];
                        if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
                            continue;
                        if (land[x][y] == 1 && visit[x][y] == 0){
                            visit[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
                oil_size.insert({cnt, oil});
                cnt++;
            }
        }
    }
}

int count_oil(vector<vector<int>> land, int col)
{
    set<int> num;
    int oil = 0;
    
    for (int i = 0; i < n; i++)
        num.insert(visit[i][col]);
    for (auto it = num.begin(); it != num.end(); it++){
        oil += oil_size.find(*it)->second;
    }
    return (oil);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    oil_size.insert({0, 0});
    find_oil(land);
    for (int i = 0; i < m; i++)
        answer = max(answer, count_oil(land, i));
    return (answer);
}

// int main()
// {
//     vector<vector<int> > land;

//     land = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};
//     cout << solution(land);

//     return (0);
// }