#include <iostream>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

int count_area(int board[100][100], int N, int rain)
{
	int cnt = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int visit[100][100] = {0};

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (board[i][j] < rain || visit[i][j] == 1)
				continue;
			queue<pair<int, int> > que;
			visit[i][j] = 1;
			que.push(make_pair(i, j));
			cnt++;
			while (!que.empty()){
				pair<int, int> cur = que.front();
				que.pop();
				for (int d = 0; d < 4; d++){
					int cur_x = cur.first + dx[d];
					int cur_y = cur.second + dy[d];
					if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N)
						continue;
					if (board[cur_x][cur_y] < rain || visit[cur_x][cur_y] == 1)
						continue;
					visit[cur_x][cur_y] = 1;
					que.push(make_pair(cur_x, cur_y));
				}
			}
		}
	}
	return (cnt);
}

int main()
{
	int N;
	int board[100][100];
	int max_num = 0;
	int min_num = 100;

	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> board[i][j];
			max_num = max(max_num, board[i][j]);
			min_num = min(min_num, board[i][j]);
		}
	}
	//
	int max_area = 0;
	for (int i = min_num; i < max_num + 1; i++){
		max_area = max(max_area, count_area(board, N, i));
	}
	cout << max_area << endl;
	return (0);
}
