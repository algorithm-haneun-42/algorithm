#include <iostream>
#include <set>

using namespace std;

int t, k, cnt;
int p[10000];
int n[1000];
void func(int num) {
	if(num >= t) {
		if(num == t) {
			cnt++;
		}
		return;
	}
	for(int i = 0; i < k; i++) {
		if(n[i] > 0) {
			n[i]--;
			func(num+p[i]);
			n[i]++;
		}
	}
}

int main(void) {
	cin >> t >> k;
	for(int i = 0; i < k; i++)
		cin >> p[i] >> n[i];
	func(0);
	cout << cnt << endl;
}