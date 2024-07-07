#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string a, b;
vector<char> A;
int main(void) {
	cin >> a >> b;
	for(char x : a)
		A.push_back(x);
	sort(A.begin(), A.end());
	long long n = 0;
	for(char x : b) {
		auto it = upper_bound(A.begin(), A.end(), x);
		long long idx = distance(A.begin(), it);
		if (idx != 0)
			idx -= 1;
		n = n*10 + A[idx] - 48;
		A.erase(A.begin() + idx);
	}
	if (to_string(n).size() != a.size() || n > stoi(b))
		cout << "-1\n";
	else
		cout << n << endl;
	return 0;
}