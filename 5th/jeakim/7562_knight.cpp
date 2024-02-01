#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int count_move(int board[300][300], int visit[300][300], pair<int, int> cur, pair<int, int> target)
{
	int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
	int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int cnt = 0;

	queue<pair<int, int> > que;
	que.push(cur);
	while()
	for(int i = 0; i < 8; i++){

	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;

	cin >> T;
	for (int t = 0; t < T; t++){
		int board[300][300] = {0};
		int visit[300][300] = {0};
		//
		int l;
		cin >> l;
		int x, y;
		cin >> x >> y;
		pair<int, int> cur = make_pair(x, y);
		cin >> x >> y;
		pair<int, int> target = make_pair(x, y);
		int cnt;
		cnt = count_move(board, visit, cur, target);
		cout << cnt << endl;
	}
	return (0);
}