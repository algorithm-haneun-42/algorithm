#include <iostream>
#include <cmath>

using namespace std;

int S, N, K, R1, R2, C1, C2;
int A[51][51];

void dfs(int r, int c, int idx, int k) {
	if (idx <= 1)
		return;
	cout << idx << " " << k << '\n';
	int m = idx / N;
	for (int i = r + (idx / 3); i < r + (idx / 3) + k; i++) {
		if (R1 <= i && i <= R2) {
			for (int j = c + (idx / 3); j < c + (idx / 3) + k; j++) {
				cout << "In :" << i << " " << j << '\n';
				if (C1 <= j && j <= C2)
					A[i - R1][j - C1] = 1;
			}
		}
		
	}
	for (int i = r; i < r + idx; i += m) {
		for (int j = c; j < c + idx; j += m) {
			cout << i << " " << j << '\n';
			if (((R1 <= i && i <= R2) || (R1 <= i + m && i + m <= R2)) &&
				((C1 <= j && j <= C2) || (C1 <= j + m && j + m <= C2)))
				dfs(i, j, m, k / N);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
	int m = pow(N, S);
	int k = K * pow(N, S - 1);
	dfs(0, 0, m, k);
	for (int i = 0; i <= R2 - R1; i++) {
		for (int j = 0; j <= C2 - C1; j++)
			cout << A[i][j];
		cout << '\n';
	}
	return 0;
}