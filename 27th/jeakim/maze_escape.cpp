#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<string> map;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int point[3][2] = {0};

void find_point()
{
	for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].size(); j++){
			if (map[i][j] == 'S'){
				point[0][0] = i;
				point[0][1] = j;
			}
			else if (map[i][j] == 'L'){
				point[1][0] = i;
				point[1][1] = j;
			}
			else if (map[i][j] == 'E'){
				point[2][0] = i;
				point[2][1] = j;
			}
		}
	}
}

int bfs_s_to_l()
{
	queue<pair<int, int> > q;
	int visited[101][101] = {0};
	int cnt = 0;
	q.push({point[0][0], point[0][1]});
	visited[point[0][0]][point[0][1]] = 1;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		if (map[cur.first][cur.second] == 'L')
			break;
		for (int i = 0; i < 4; i++){
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size())
				continue;
			if (map[x][y] != 'X' && visited[x][y] == 0){
				q.push({x, y});
				visited[x][y] = visited[cur.first][cur.second] + 1;
			}
		}
	}
	return (visited[point[1][0]][point[1][1]] - 1);
}

int bfs_l_to_e()
{
	queue<pair<int, int> > q;
	int visited[101][101] = {0};
	int cnt = 0;
	q.push({point[1][0], point[1][1]});
	visited[point[1][0]][point[1][1]] = 1;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		if (map[cur.first][cur.second] == 'E')
			break;
		for (int i = 0; i < 4; i++){
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];
			if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size())
				continue;
			if (map[x][y] != 'X' && visited[x][y] == 0){
				q.push({x, y});
				visited[x][y] = visited[cur.first][cur.second] + 1;
			}
		}
	}
	return (visited[point[2][0]][point[2][1]] - 1);
}

int solution(vector<string> maps) {
    int answer = 0;
	int tmp;

	map = maps;
	find_point();
	tmp = bfs_s_to_l();
	if (tmp < 0)
		return (-1);
	answer += tmp;
	cout << endl;
	tmp = bfs_l_to_e();
	if (tmp < 0)
		return (-1);
	answer += tmp;
    return answer;
}

int main()
{
	vector<string> maps = {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"};
	cout << solution(maps) << endl;

	return (0);
}