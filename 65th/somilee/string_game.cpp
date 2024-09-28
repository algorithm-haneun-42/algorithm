#include <iostream>
#include <algorithm>

using namespace std;

int n;
int c[7];
int cub[7];
int sum[10001][7];
int main(void) {
	cin >> n;
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= 6; i++)
			cin >> c[i];
		cub[c[1]] = c[6]; cub[c[6]] = c[1];
		cub[c[2]] = c[4]; cub[c[4]] = c[2];
		cub[c[3]] = c[5]; cub[c[5]] = c[3];
		for(int i = 1; i <= 6; i++) {
			int s = sum[k-1][cub[i]];
			if(cub[i] == 6) {
				if(i == 5)
					sum[k][i] = sum[k-1][cub[i]] + 4;
				else
					sum[k][i] = sum[k-1][cub[i]] + 5;
			}
			else if(i == 6) {
				if(cub[i] == 5)
					sum[k][i] = sum[k-1][cub[i]] + 4;
				else
					sum[k][i] = sum[k-1][cub[i]] + 5;
			}
			else
				sum[k][i] = sum[k-1][cub[i]] + 6;
		}
	}
	int ans = 0;
	for(int i = 1; i <= 6; i++)
		ans = max(ans, sum[n][i]);
	cout << ans << endl;
}