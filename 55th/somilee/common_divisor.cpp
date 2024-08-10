#include <iostream>
#include <set>

using namespace std;

int n, m, mul;
bool check_disjoint(int i) {
	for(int j = 2; j*j <= i; j++) {
		if (i%j == 0 && (mul/i)%j == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	cin >> n >> m;
	mul = m/n;
	set<pair<int, int>, greater<pair<int, int>>> s;
	for(int i = 1; i*i <= mul; i++)
		if (mul%i == 0 && check_disjoint(i))
			s.insert({i, mul/i});
	cout << s.begin()->first * n << ' ' << s.begin()->second *n << endl;
	return 0;
}