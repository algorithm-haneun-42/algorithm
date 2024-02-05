#include <iostream> //ㅍㅛ준입출력
#include <queue>  //큐
#include <algorithm> //
using namespace std;

#define X first
#define Y second
#define MAX 100

int board[MAX][MAX];
int vis[MAX][MAX] = {0, };
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue <pair<int, int> > Q;
int result;

void bft(int x, int y)
{
	Q.push({x,y});
	vis[x][y] = 1;
	int count = 0;

	while(!Q.empty())
	{
		int tmp_x = Q.front().first;
		int tmp_y = Q.front().second;
		Q.pop();
		count = 0;
		for(int i=0; i<4; i++)
		{
			int nx = tmp_x+dx[i];
            int ny = tmp_y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
			if(board[nx][ny] <= 0 && vis[nx][ny] == 0)
			{
				count++;
				vis[nx][ny] = 1;
			}
            if(board[nx][ny] > 0 && vis[nx][ny] == 0)
            {
				Q.push({nx,ny});
				vis[nx][ny]=1;
				// cnt++;
			}
				
				
		}
			board[tmp_x][tmp_y] -= 1;
	}
}

void print_board()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
    }
	cout << endl;
	cout << endl;
}

int main(void) {
	cin >> n >> m;;
	int count;
	int result = 0;
	int max = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> board[i][j];
		}
    }
	for(int h = 0; h < 10; h++)
	{
		count = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(board[i][j] > 0 &&  vis[i][j] == 0)
				{
					bft(i,j);
					count++;
				}
			}
		}
		// cout << h << "번째" << endl;
		// print_board();

		if (count > 1)
		{
			cout << h << endl;
			return 0;
		}
		if (count == 0)
			break;
		fill(&vis[0][0], &vis[n][n], 0);
	}
	cout << 0 << endl;
    return 0;
}
