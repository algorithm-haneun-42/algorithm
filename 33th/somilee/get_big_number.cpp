#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string num = number;
	sort(num.begin(), num.end());
	for(int i = 0; i < k; i++) {
		auto it = find(number.begin(), number.end(), num[i]);
		number.erase(it);
	}
    return number;
}

int main(void) {
	string number = "4177252841";
	int k = 4;
	cout << solution(number, k) << '\n';
}