#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> A;
string a;
int b;
int main(void) {
	cin >> a >> b;
	for(char x : a)
		A.push_back(x - 48);
	sort(A.begin(), A.end(), greater<int>());
    do {
		if (A[0] == 0)
			continue;
		int sum = 0;
        for (int num : A) {
			sum = sum*10 + num;
        }
        if (sum < b) {
			cout << sum << endl;
			return 0;
		}
    } while (prev_permutation(A.begin(), A.end()));
	cout << "-1\n" << endl;
	return 0;
}