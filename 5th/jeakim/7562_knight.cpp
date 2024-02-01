#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int count_move(int board[300][300], int visit[300][300], int l, pair<int, int> start, pair<int, int> target)
{
	int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int cnt = 0;

	queue<pair<int, int> > que;
	visit[start.first][start.second] = 0;
	que.push(start);
	while(!que.empty()){
		pair<int, int> cur = que.front();
		que.pop();
		if (cur == target)
			break;
		for(int i = 0; i < 8; i++){
			int cur_x = cur.first + dx[i];
			int cur_y = cur.second + dy[i];
			if (cur_x >= l || cur_x < 0 || cur_y >= l || cur_y < 0)
				continue;
			if (visit[cur_x][cur_y] >= 0)
				continue;
			visit[cur_x][cur_y] = visit[cur.first][cur.second] + 1;
			que.push(make_pair(cur_x, cur_y));
		}
	}
	return (visit[target.first][target.second]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;
	for (int t = 0; t < T; t++){
		int board[300][300] = {0};
		int visit[300][300] = {-1};
		//
		int l;
		cin >> l;
		int x, y;
		cin >> x >> y;
		pair<int, int> start = make_pair(x, y);
		cin >> x >> y;
		pair<int, int> target = make_pair(x, y);
		int cnt;
		cnt = count_move(board, visit, l, start, target);
		cout << cnt << endl;
	}
	return (0);
}