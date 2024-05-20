#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
	int cnt = 0;
	if (x < y) {
		if (x+n <= y)
			cnt += solution (x+n, y, n);
		if (x*2 <= y)
			cnt += solution (x*2, y, n);
		if (x*3 <= y)
			cnt += solution (x*3, y, n);
	}
	if (x == y)
		cnt ++;
	return (cnt);
}

int main(void) {
	cout << solution(10, 40, 5) << '\n';
}