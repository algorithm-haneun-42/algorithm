#include <iostream>

using namespace std;

int n;
long long b[1005][6];
int main(void) {
	cin >> n;
	b[1][0] = 1; b[1][1] = 1; b[1][2] = 0; b[1][3] = 1; b[1][4] = 0; b[1][5] = 0;
	for(int i = 2; i <= n; i++) {
		b[i][0] = (b[i-1][0] + b[i-1][1] + b[i-1][2]) % 1000000;
		b[i][1] = b[i-1][0];
		b[i][2] = b[i-1][1];
		b[i][3] = (b[i-1][0] + b[i-1][1] + b[i-1][2] + b[i-1][3] + b[i-1][4] + b[i-1][5]) % 1000000;
		b[i][4] = b[i-1][3];
		b[i][5] = b[i-1][4];
	}
	long long sum = 0;
	for(int i = 0; i < 6; i++) {
		sum = (sum + b[n][i]) % 1000000;
	}
	cout << sum << endl;
}