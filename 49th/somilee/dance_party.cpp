#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<int> m, f;

int main(void) {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> num;
		m.push_back(num);
	}
	for(int i = 0; i < n; i++) {
		cin >> num;
		f.push_back(num);
	}
	sort(m.begin(), m.end());
	sort(f.begin(), f.end());
	
}