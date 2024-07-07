#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, l, a;
vector<int> v, r;
int main(void) {
	cin >> n >> m >> l;
	for(int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int start = 0;
	for(int x : v) {
		r.push_back(x - start);
		start = x;
	}
	r.push_back(l - v.back());
	int div;
	for(div = 1; div <= v.back(); div++) {
		int sum = 0;
		for(int x : r) {
			sum += x / div;
			if (x % div == 0)
			 	sum--;
		}
		if (sum == m)
			break;
	}
	cout << div << endl;
}