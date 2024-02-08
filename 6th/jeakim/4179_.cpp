#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void input_set(int miro[100][100], int m_fire[100][100], int m_jh[100][100], queue<pair<int, int> > q_fire, queue<pair<int, int> > q_jh, int R, int C)
{
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			cin >> miro[r][c];
			if (miro[r][c] == 'J'){
				q_jh.push(make_pair(r, c));
				m_jh[r][c] = 1;
			}
			else if (miro[r][c] == 'F'){
				q_fire.push(make_pair(r, c));
				m_fire[r][c] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	int miro[100][100];
	int m_fire[100][100];
	int m_jh[100][100];
	queue<pair<int, int> > q_fire;
	queue<pair<int, int> > q_jh;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	//
	cin >> R >> C;
	input_set(miro, m_fire, m_jh, q_fire, q_jh, R, C);
	//불 확산
	while (!q_fire.empty()){
		pair<int, int> cur = q_fire.front();
		q_fire.pop();
		for (int i = 0; i < 4; i++){
			int cur_x = cur.first + dx[i];
			int cur_y = cur.second + dy[i];
			if (cur_x < 0 || cur_x >= R || cur_y < 0 || cur_y >= C)
				continue;
			if (m_fire[cur_x][cur_y] > 0 || miro[cur_x][cur_y] == '#')
				continue;
			m_fire[cur_x][cur_y] = m_fire[cur.first][cur.second] + 1;
			q_fire.push(make_pair(cur_x, cur_y));
		}
	}
	//지훈
	while (!q_jh.empty()){
		pair<int, int> cur = q_jh.front();
		q_jh.pop();
		for(int i = 0; i < 4; i++){
			int cur_x = cur.first + dx[i];
			int cur_y = cur.second + dy[i];
			if (cur_x < 0 || cur_x >= R || cur_y < 0 || cur_y >= C){
				cout << m_jh[cur.first][cur.second] + 1 << endl;
				return (0);
			}
			if (m_jh[cur_x][cur_y] >= 0 || miro[cur_x][cur_y] == '#')
				continue;
			if (m_fire[cur_x][cur_y] != 0 && m_fire[cur_x][cur_y] <= m_jh[cur_x][cur_y] + 1)
				continue;
			m_jh[cur_x][cur_y] = m_jh[cur.first][cur.second] + 1;
			q_jh.push(make_pair(cur_x, cur_y));
		}
	}
	cout << "IMPOSSIBLE" << endl; 
	return (0);
}
