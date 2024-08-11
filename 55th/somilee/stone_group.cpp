#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int a, b, c;
queue< tuple<int, int, int> > Q;
bool vis[500][500][500];

bool check_ops 

int main(void) {
	cin >> a >> b >> c;
	Q.push({a, b, c});
	vis[a][b][c] = 1;
	while(!Q.empty()) {
		tie(a, b, c) = Q.front(); Q.pop();
		if (a == b && b == c) {
			cout << "1" << endl;
			return 0;
		}
		if ((a < b) && (vis[a*2][b-a][c] == 0)) {
			Q.push({a*2, b-a, c});
			vis[a*2][b-a][c] = 1; 
		}
		if ((a < c) && (vis[a*2][b][c-a] == 0)) {
			Q.push({a*2, b, c-a});
			vis[a*2][b][c-a] = 1; 
		}
		if ((b < c) && (vis[a][b*2][c-b] == 0)) {
			Q.push({a, b*2, c-b});
			vis[a][b*2][c-b] = 1; 
		}
		if ((b < a) && (vis[a-b][b*2][c] == 0)) {
			Q.push({a-b, b*2, c});
			vis[a-b][b*2][c] = 1; 
		}
		if ((c < a) && (vis[a-c][b][c*2] == 0)) {
			Q.push({a-c, b, c*2});
			vis[a-c][b][c*2] = 1; 
		}
		if ((c < b) && (vis[a][b-c][c*2] == 0)) {
			Q.push({a, b-c, c*2});
			vis[a][b-c][c*2] = 1; 
		}
	}
	cout << "0" << endl;
	return 0;
}