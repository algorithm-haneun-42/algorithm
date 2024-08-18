#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int x, n;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1) {
		cin >> x >> n;
		if (cin.eof())
			break;
		set<int> s;
		map<int, int> m;
		while (n--) {
			int num; cin >> num;
			auto it = s.lower_bound(x*10000000 - num);
			if (it != s.end() && *it == x*10000000 - num) {
				int a = min(num, x*10000000 - num);
				m.insert({a, x*10000000 - a});
			}
			else
				s.insert(num);
		}
		if (m.size() == 0)
			cout << "danger\n";
		else
			cout << "yes " << m.begin()->first << " " << m.begin()->second << endl;
	}
	return 0;
}