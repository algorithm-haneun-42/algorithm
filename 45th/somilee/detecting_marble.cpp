#include <iostream>
#include <queue>

using namespace std;

int n, m;
int w[100][100];
int v[100];
int main(void){
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		w[a][b] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			cout << w[i][j] << ' ';
		cout << endl;
	}
	queue <int> Q;
	for(int i = 1; i <= n; i++) {
		int flag = 0;
		for(int j = 1; j <= n; j++) {
			if (w[i][j] == 1)
				flag = 1;
		}
		if (flag == 0) {
			Q.push(i);
			v[i]++;
		}
	}
	while (!Q.empty()) {
		int cur = Q.back(); Q.pop();
		for(int i = 1; i <= n; i++) {
			if (w[i][cur] == 1) {
				v[i] += v[cur];
			}
		}
	}
}