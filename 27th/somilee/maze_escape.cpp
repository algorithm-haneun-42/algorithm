#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int find_road(char start, char end, vector<string> maps) {
    int vis[105][105] = {0};
	for(int i = 0; i < maps.size(); i++) {
		for(int j = 0; j < maps[0].length(); j++) {
			if (maps[i][j] == start) {
				queue<pair<int, int> > Q;
				vis[i][j] = 1;
				Q.push({i, j});
				int n = 0;
				while (!Q.empty()) {
					int q_size = Q.size();
					for(int z = 0; z < q_size; z++){
						pair<int, int> cur = Q.front();
						if (maps[cur.X][cur.Y] == end)
							return (n);
						Q.pop();
						for (int dir = 0; dir < 4; dir ++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].length())
								continue;
							if (vis[nx][ny] == 1 || maps[nx][ny] == 'X')
								continue;
							vis[nx][ny] = 1;
							Q.push({nx, ny});
						}
					}
					n++;
				}
			}
		}
	}
	return (-1);
}

int solution(vector<string> maps) {
	int a = find_road('S', 'L', maps);
	int b = find_road('L', 'E', maps);
	if (a == -1 || b == -1)
		return (-1);
	else return (a+b);
}

int main(void) {
	vector<string> maps;
	maps = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
	cout << solution(maps);
}