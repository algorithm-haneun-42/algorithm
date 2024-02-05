#include <iostream> //ㅍㅛ준입출력
#include <queue>  //큐
#include <algorithm> //
using namespace std;

#define X first
#define Y second
#define MAX 100

int board[MAX][MAX];
int vis[MAX][MAX] = {0, };
int n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue <pair<int, int> > Q;
int result;

void bft(int x, int y, int h)
{
	Q.push({x,y});
	vis[x][y] = 1;

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
            if(board[nx][ny] > h && vis[nx][ny] == 0)
            {
				Q.push({nx,ny});
				vis[nx][ny]=1;
				// cnt++;
			}
		}
	}
}

int main(void) {
	cin >> n;
	int count;
	int result = 0;
	int max = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] > max)
				max = board[i][j];
		}
    }
	for(int h = 0; h < max; h++)
	{
		count = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(board[i][j] > h &&  vis[i][j] == 0)
				{
					
					bft(i,j, h);
					count++;
				}
			}
		}
		if (result < count)
			result = count;
		fill(&vis[0][0], &vis[n][n], 0);
	}
	cout << result << endl;
    return 0;
}
