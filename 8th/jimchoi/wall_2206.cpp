#include <iostream> //ㅍㅛ준입출력
#include <queue>  //큐
#include <algorithm> //
using namespace std;

string board[1002];
int d[1001][1001];
int vis[1001][1001];
int m, n;



int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue <pair<pair<int, int>, int >> Q;

int bfs(int start)
{
	int breaks = 0;
	pair<int, int> end;
	end.first = n;
	end.second = m;
	Q.push({{0,0},1});
	vis[0][0] = 1;
	while (!Q.empty())
	{
		pair <pair <int, int> ,int > now;
		now.first.first = Q.front().first.first;
		now.first.second = Q.front().first.second;
		now.second = Q.front().first.second;
		vis[now.first.first][now.first.second] = 1;
		Q.pop();
		
		if (now == end)
			return (0);
		for (int i = 0; i < 4; i++)
		{
			int nx = now.first.first+dx[i];
            int ny = now.first.second+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(board[nx][ny] == 1 && breaks == 1) continue;
			if(board[nx][ny] == 1 )
				breaks = 1;
			Q.push({{nx,ny}, now.second + 1});
			vis[nx][ny] = 1;
	}
}
}