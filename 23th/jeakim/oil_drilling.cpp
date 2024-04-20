#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int count_oil(vector<vector<int>> land, int col)
{
    int oil = 0;
    int visit[501][501] = {0};
    queue<pair<int, int> > q;

    for (int row = 0; row < n; row++){
        if (land[row][col] == 1 && visit[row][col] == 0){
            q.push({row, col});
            visit[row][col] = 1;
            while (!q.empty()){
                pair<int, int> cur;
                cur = q.front();
                q.pop();
                visit[cur.first][cur.second] = 1;
                oil++;
                for (int i = 0; i < 4; i++){
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
                        continue;
                    if (land[x][y] == 1 && visit[x][y] == 0){
                        visit[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
    return (oil);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    n = land.size();
    m = land[0].size();
    for (int j = 0; j < m; j++)
        answer = max(answer, count_oil(land, j));
    return answer;
}