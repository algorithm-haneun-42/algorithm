#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> P;
vector<int> N;
int main(void) {
	cin >> n;
	while(n--) {
		int a; cin >> a;
		if (a > 0)
			P.push_back(a);
		else
			N.push_back(a);
	}
	sort(P.begin(), P.end());
	sort(N.begin(), N.end());

	
	int sum = 0;
	while (P.size() > 1) {
		cout << sum << endl;
		if (P.size() == 1) {
			sum += P[0];
			break;
		}
		sum += P[0]*P[1];
		P.erase(P.begin(), P.begin() + 2);
	}
	while (N.size() > 1) {
		cout << sum << endl;
		if (N.size() == 1) {
			sum += N[0];
			break;
		}
		sum += N[0]*N[1];
		N.erase(N.begin(), N.begin() + 2);
	}
	cout << sum << endl;
	return 0;
}