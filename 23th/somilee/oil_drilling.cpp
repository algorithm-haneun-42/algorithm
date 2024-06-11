#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};


int solution(vector<vector<int>> land){
    size_t land_rows = land.size();
    size_t land_cols = land[0].size();
    int answer = 0;

    int vis[505][505] = {0};
    int num = 0;
    int area[300] = {0};
    for(int i = 0; i < land_rows; i++){
        for(int j = 0; j < land_cols; j++){
            if(land[i][j] == 0 || vis[i][j] > 0)
                continue;
            num++;
            queue<pair<int, int> > Q;
            vis[i][j] = num;
            Q.push({i, j});
            while(!Q.empty()){
                area[num]++;
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= land_rows || ny >= land_cols)
                        continue;
                    if(land[nx][ny] == 0 || vis[nx][ny] > 0)
                        continue;
                    vis[nx][ny] = num;
                    Q.push({nx, ny});
                }
            }
        }
    }

    for(int j = 0; j < land_cols; j++){
        set<int> A;
        int sum = 0;
        for(int i = 0; i < land_rows; i++){
            if(vis[i][j] == 0)
                continue;
            A.insert(vis[i][j]);
        }
        for(int n: A)
            sum += area[n];
        answer = max(sum, answer);
    }
    return answer;
}
// vector<vector<int>> land = {{0, 0, 0, 1, 1, 1, 0, 0},
//                     {0, 0, 0, 0, 1, 1, 0, 0},
//                     {1, 1, 0, 0, 0, 1, 1, 0},
//                     {1, 1, 1, 0, 0, 0, 0, 0},
//                     {1, 1, 1, 0, 0, 0, 1, 1}};
// size_t land_rows = 5;
// size_t land_cols = 8;

// int main(void){
//     int ans = solution(land);
//     cout << ans;
// }