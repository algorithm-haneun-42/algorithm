#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
	int b[2005] = {0};
	b[1] = 1;
	b[2] = 2;
	for(int i = 3; i <= n; i++)
		b[i] = (b[i-1] + b[i-2])%1234567;
	return b[n];
}

int main(void) {
	cout << solution(4) << '\n';
}