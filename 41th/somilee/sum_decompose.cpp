#include <iostream>

using namespace std;

int n, k;
int b[2002][2002];
int main(void) {
	cin >> n >> k;
	for(int i = 0; i <= n; i++) {
		b[i][1] = 1; b[0][i] = 1;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int sum = 0;
			for(int k = 1; k < i; k++) {
				sum += b
			}
		}
	}
	cout << sum << endl;
}
// int sumDecom(int n, int k) {
// 	int sum = 0;
// 	if (k == 1)
// 		return 1;
// 	else
// 		for(int i = 0; i <= n; i++)
// 			sum = (sum + sumDecom(n-i, k-1))%1000000000;
// 	return sum;
// }

// int main(void) {
// 	cin >> n >> k;
// 	cout << sumDecom(n, k) << endl;
// }