#include <iostream>
#include <queue>
#include <functional>

using namespace std;

#define X first
#define Y second
char board[25][25];
bool vis[25][25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++){
			cin >> board[i][j];
		}
	}

	int num = 0;
	priority_queue<int, vector<int>, greater<int>> q;
//	vector<int> ans_list;
	for(int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (board[i][j] == '0' || vis[i][j] == 1)
				continue;
			num ++;
			queue<pair<int, int> > Q;
			vis[i][j] = 1;
			Q.push({i,j});
			int area = 0;
			while (!Q.empty())
			{
				area ++;
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir ++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (vis[nx][ny] == 1 || board[nx][ny] == '0')
						continue;
					vis[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			q.push(area);
//			ans_list.push_back(area);
		}
	}
	cout << num << '\n';
//	cout << ans_list.size() << '\n';
	//sort(ans_list.begin(), ans_list.end());
	//for (int i = 0; i < ans_list.size(); i++) {
//		cout << ans_list[i] << "\n";
//	}
	for(int i = 0; i < num; i ++)
	{
		int a = q.top();
		q.pop();
		cout << a << '\n';
	}
}
