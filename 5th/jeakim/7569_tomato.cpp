#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int check_flag(int tomato[100][100][100], int M, int N, int H)
{
	int flag = 1;

	for (int m = 0; m < M; m++){
		for (int n = 0; n < N; n++){
			for (int h = 0; h < H; h++){
				if (tomato[m][n][h] == 0)
					flag = -1;
			}
		}
	}
	return (flag);
}

int count_days(int tomato[100][100][100], int visit[100][100][100], int M, int N, int H)
{
	int max_day = 1;
	queue<pair<pair<int, int>, int> > que;
	int dm[6] = {1, 0, 0, -1, 0, 0};
	int dn[6] = {0, 1, 0, 0, -1, 0};
	int dh[6] = {0, 0, 1, 0, 0, -1};

	for (int m = 0; m < M; m++){
		for (int n = 0; n < N; n++){
			for (int h = 0; h < H; h++){
				if (tomato[m][n][h] == 0 || tomato[m][n][h] == -1)
					continue;
				if (visit[m][n][h] > 0)
					continue;
				que.push(make_pair(make_pair(m, n), h));
				visit[m][n][h] = 1;
				while (!que.empty()){
					pair<pair<int, int>, int> cur = que.front();
					que.pop();
					tomato[cur.first.first][cur.first.second][cur.second] = 1;
					for (int d = 0; d < 6; d++){
						int cur_m = cur.first.first + dm[d];
						int cur_n = cur.first.second + dn[d];
						int cur_h = cur.second + dh[d];
						if (cur_m < 0 || cur_n < 0 || cur_h < 0 || cur_m >= M || cur_n >= N || cur_h >= H)
							continue;
						if (tomato[cur_m][cur_n][cur_h] == -1 || tomato[cur_m][cur_n][cur_h] == 1)
							continue;
						if (visit[cur_m][cur_n][cur_h] > 0)
							continue;
						visit[cur_m][cur_n][cur_h] = visit[cur.first.first][cur.first.second][cur.second] + 1;
						que.push(make_pair(make_pair(cur_m, cur_n), cur_h));
						max_day = max(max_day, visit[cur_m][cur_n][cur_h]);
					}
				}
			}
		}
	}
	return (max_day -1);
}

// int count_max(int visit[100][100][100], int M, int N, int H)
// {
// 	int max_day = 0;

// 	for (int m = 0; m < M; m++){
// 		for (int n = 0; n < N; n++){
// 			for (int h = 0; h < H; h++){
// 				max_day = max(max_day, visit[m][n][h]);
// 			}
// 		}
// 	}
// 	return (max_day - 1);
// }

void print_visit(int visit[100][100][100], int M, int N, int H)
{
	for (int m = 0; m < M; m++){
		for (int n = 0; n < N; n++){
			for (int h = 0; h < H; h++){
				cout << visit[m][n][h] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int M, N, H;
	int tomato[100][100][100];
	int visit[100][100][100] = {0};
	int max_day;

	cin >> H >> N >> M;
	for (int m = 0; m < M; m++){
		for (int n = 0; n < N; n++){
			for (int h = 0; h < H; h++){
				cin >> tomato[m][n][h];
			}
		}
	}
	max_day = count_days(tomato, visit, M, N, H);
	//print_visit(visit, M, N, H);
	if (check_flag(tomato, M, N, H) == -1)
		cout << -1 << endl;
	else
		cout << max_day << endl ;
	return (0);
}
