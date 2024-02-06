#include <iostream> //ㅍㅛ준입출력
#include <queue>  //큐
// #include <cstring>  //스트링
// #include <utility> // pair ㅋㅡㄹ래스
#include <algorithm> //
using namespace std;

#define X first
#define Y second

string board[26];
int vis[25][25] = {0, };
int n, cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue <pair<int, int> > Q;
vector<int> result;

int bft(int x, int y)
{
	cnt = 0;
	Q.push({x,y});
	vis[x][y]=1;
	cnt++;

	while(!Q.empty())
	{
		int tmp_x = Q.front().first;
		int tmp_y = Q.front().second;
		Q.pop();
		for(int i=0; i<4; i++)
		{
			int nx = tmp_x+dx[i];
            int ny = tmp_y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(board[nx][ny]== '1' && vis[nx][ny] == 0)
            {
				Q.push({nx,ny});
            	vis[nx][ny]=1;
            	cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	cin >> n;

	for(int i=0; i<n; i++)
	{
        cin >> board[i];
    }
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(board[i][j] == '1'&&  vis[i][j] == 0)
			{
				cnt = 0;
				
				result.push_back(bft(i,j));
			}
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for(int i=0; i<result.size(); i++)
		cout << result[i] << "\n";

    return 0;
}
