#include <iostream>

using namespace std;

string S;

int recursive(string &s, int &idx) {
	int ret = 0;
	int prev;
	for (; idx < s.size(); idx++) {
		if (s[idx] == '(') {
			ret--; 
			ret += prev * recursive(s, ++idx);
		}
		else if (s[idx] == ')')
			break;
		else {
			prev = s[idx] - '0';
			ret++;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
	int idx = 0;
	cout << recursive(S, idx) << '\n';
	return 0;
}