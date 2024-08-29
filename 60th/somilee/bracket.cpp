#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long c[5001];
int main(void) {
	cin >> n;
	c[0] = 1;
	for(int i = 2; i <= 5000; i = i+2)
		for(int j = i - 2; j >= 0; j = j-2)
			c[i] = (c[i] + c[i - 2 - j] * c[j]) % 1000000007;
	for(int i = 0; i < n; i++) {
		int num; cin >> num;
		cout << c[num] << endl;
	}
}