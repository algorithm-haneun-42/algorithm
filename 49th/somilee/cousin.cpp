#include <iostream>
#include <vector>

using namespace std;

int n, k, a, b;
// int b[1005];
vector<int> V;
int main(void) {
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0)
			break;
		int cnt = 1;
		cin >> a;
		for(int i = 1; i < n; i++) {
			cin >> b;
			if (b - a == 1)
				cnt++;
			else {
				V.push_back(cnt);
				cnt = 1;
			}
			a = b;
		}
		cout << "* ";
		for(int a : V)
			cout << a << ' ';
		cout << " *" << endl;
	}
}