#include <iostream>

using namespace std;

unsigned long long n, k, cnt;
int b[200005];
int main(void) {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++) {
		int sum = 0;
		for(int j = 0; j < 1; j++)
			sum += b[j];
		if(sum == k)
			cnt++;
		for(int j = i; j < n; j++) {
			cout << sum << " : ";
			sum += b[j];
			if(sum == k)
				cnt++;
		}
	}
	cout << cnt << endl;
}