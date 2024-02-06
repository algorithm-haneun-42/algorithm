#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void print_board(int board[25][25], int N)
{
	cout << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int board[25][25] = {0};
	int visit[25][25] = {0};
	int N;
	int num = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	vector<int> st;

	cin >> N;
	string s[25];
	for (int i = 0; i < N; i++){
		cin >> s[i];
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			board[i][j] = s[i][j] - '0';
		}
	}
	//print_board(board, N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (board[i][j] == 0 || visit[i][j] > 0)
				continue;
			queue<pair<int, int> > que;
			num++;
			visit[i][j] = num;
			que.push(make_pair(i, j));
			int area = 1;
			while (!que.empty()){
				pair <int, int> cur = que.front();
				que.pop();
				for (int d = 0; d < 4; d++){
					int cur_x = cur.first + dx[d];
					int cur_y = cur.second + dy[d];
					if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N)
						continue;
					if (board[cur_x][cur_y] == 0 || visit[cur_x][cur_y] > 0)
						continue;
					visit[cur_x][cur_y] = num;
					que.push(make_pair(cur_x, cur_y));
					area++;
				}
			}
			st.push_back(area);
		}
	}
	cout << num << endl;
	sort(st.begin(), st.end());
	for (int i = 0; i < st.size(); i++)
		cout << st[i] << endl;
	return (0);
}
