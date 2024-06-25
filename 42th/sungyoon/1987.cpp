#include <iostream>

using namespace std;

int R, C;
char A[21][21];
bool visit[26];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int r, int c, int cnt) {
	int ret = 0;

	if (visit[A[r][c]]) {
		return cnt - 1;
	}

	visit[A[0][0]] = true;

	for (int i = 0; i < 4; i++) {
		int nc = c + dx[i];
		int nr = r + dy[i];
		if (0 <= nc && nc < C && 0 <= nr && nr < R) {
			visit[A[r][c]] = true;
			ret = max(ret, dfs(nr, nc, cnt + 1));
			visit[A[r][c]] = false;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
			A[i][j] -= 'A';
		}
	}

	int answer = dfs(0, 0, 1);
	if (answer == 0) answer = 1;
	cout << answer << '\n';
	return 0;
}