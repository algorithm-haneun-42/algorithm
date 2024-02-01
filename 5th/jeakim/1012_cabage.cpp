#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void input_board(int board[50][50], int K)
{
	for (int i = 0; i < K; i++){
		int x, y;
		cin >> x >> y;
		board[y][x] = 1;
	}
}

void print_board(int board[50][50], int N, int M)
{
	cout << endl;
	for(int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int count_board(int board[50][50], int visit[50][50], int N, int M)
{
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int cnt = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (visit[i][j] == 1 || board[i][j] == 0)
				continue;
			cnt++;
			queue<pair<int , int> > que;
			que.push(make_pair(i, j));
			visit[i][j] = 1;
			while(!que.empty()){
				pair<int, int> cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++){
					int cur_x = cur.first + dx[k];
					int cur_y = cur.second + dy[k];
					if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= M)
						continue;
					if (visit[cur_x][cur_y] == 1 || board[cur_x][cur_y] == 0)
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T, M, N, K;

	cin >> T;
	for (int t = 0; t < T; t++){
		int board[50][50] = {0};
		int visit[50][50] = {0};
		//입력
		cin >> M >> N >> K;
		input_board(board, K);
		//출력
		//print_board(board, N, M);
		//이동
		cout << count_board(board, visit, N, M) << endl;
	}
	return (0);
}