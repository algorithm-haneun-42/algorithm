#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;

int div_four(int N, int r, int c) {
	int n = pow(2, N) / 2;
	if (r < n && c < n) {
		if (N == 1) return 0;
		return 0 * pow(n, 2) + div_four(N-1, r, c);
	}
	else if (r < n && c >= n) {
		if (N == 1) return 1;
		return 1 * pow(n, 2) + div_four(N-1, r, c-n);
	}
	else if (r >= n && c < n) {
		if (N == 1) return 2;
		return 2 * pow(n, 2) + div_four(N-1, r-n, c);
	}
	else {
		if (N == 1) return 3;
		return 3 * pow(n, 2) + div_four(N-1, r-n, c-n);
	}
}

int main(void) {
	cin >> N >> r >> c;
	cout << div_four(N, r, c) << endl;
}