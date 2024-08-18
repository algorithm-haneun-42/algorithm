#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, s;
int c[50005][50005];
int main(void) {
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		c[b][a] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}
	// for(int i = 1; i <= n; i++)
	// 	for(int j = 1; j <= n; j++)
	// 		c[i][j] = h[i][j];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if (c[i][k] + c[k][j] != 0)
					c[i][j] = c[i][k] + c[k][j];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}
	cin >> s;
	for(int i = 0; i < s; i++) {
		int a, b; cin >> a >> b;
		if (c[b][a] > 0)
			cout << "1\n";
		else if (c[a][b] > 0)
			cout << "-1]n";
		else cout << "0\n";
	}
	return 0;
}