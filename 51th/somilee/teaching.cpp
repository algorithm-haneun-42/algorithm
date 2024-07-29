#include <iostream>
#include <set>

using namespace std;

int n, k;
string str[50];
set<char> a[50];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> str[i];
	if (k < 5)
		return 0;
	for(int i = 0; i < n; i++) {
		for(int j = 4; j < str[i].size()-4; j++) {
			a[i].insert(str[i][j]);
		}
	}
}