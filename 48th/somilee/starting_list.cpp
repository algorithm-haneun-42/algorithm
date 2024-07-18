#include <iostream>
#include <algorithm>

using namespace std;

int b[15][15];
bool isused[11];
int arr[11];
int ans;
void func(int k) {
	if (k == 11) {
		int sum = 0;
		for(int i = 0; i < 11; i++)
			sum += arr[i];
		ans = max(ans, sum);
		return;
	}
	for(int i = 0; i < 11; i++) {
		if (b[i][k] != 0 && !isused[i]) {
			arr[k] = b[i][k];
			isused[i] = 1;
			func(k+1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	int c; cin >> c;
	while(c--) {
		ans = 0;
		for(int i = 0; i < 11; i++)
			for(int j = 0; j < 11; j++)
				cin >> b[i][j];
		func(0);
		cout << ans << endl;
	}
}
