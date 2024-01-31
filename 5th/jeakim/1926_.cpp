#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void input_board(int board[500][500], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
}

void print_board(int board[500][500], int N, int M)
{
	cout << endl;
	for(int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int count_area(int board[500][500], int visit[500][500], queue<pair<int, int> > que, int n, int m)
{
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {-1, 0, 1, 0};
	int area = 0;

	while (!que.empty()){
		pair<int, int> cur = que.front();
		que.pop();
		area++;
		for(int k = 0; k < 4; k++){
			int cur_x = cur.first + dx[k];
			int cur_y = cur.second + dy[k];
			if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m)
				continue;
			if (board[cur_x][cur_y] == 0 || visit[cur_x][cur_y] == 1)
				continue;
			visit[cur_x][cur_y] = 1;
			que.push(make_pair(cur_x, cur_y));
		}
	}
	return (area);
}

// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	int n, m;
// 	int board[500][500];
// 	int visit[500][500] = {0};
// 	int num = 0;
// 	int max_area = 0;

// 	//입력
// 	cin >> n >> m;
// 	input_board(board, n, m);
// 	//출력
// 	//print_board(board, n, m);
// 	//
// 	for(int i = 0; i < n; i++){
// 		for (int j = 0; j < m; j++){
// 			if (board[i][j] == 0 || visit[i][j] == 1)
// 				continue;
// 			int area;
// 			num++;
// 			visit[i][j] = 1;
// 			queue<pair<int, int> > que;
// 			que.push(make_pair(i, j));
// 			area = count_area(board, visit, que, n, m);
// 			max_area = max(max_area, area);
// 		}
// 	}
// 	cout << num << endl << max_area << endl;
// 	return (0);
// }