#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int solution(int n, long long l, long long r) {
//     int sum = 0;
// 	int start, end;
// 	start = l;
// 	if (n == 0)
// 		sum = 1;
// 	else {
// 		for(int num = l/5 + 1; num*5 < r; num++) {
// 			if (num*5 < r)
// 				end = num*5;
// 			else end = r;
// 			int term = end - start + 1;
// 			if (term >= 3)
// 				term--;
// 			sum += solution(n-1,(num-1)*5 + 1, num*5)/4*term;
// 			start = end + 1;
// 		}
// 	}
// 	return (sum);
// }

int solution(int n, long long l, long long r) {
    int sum = 0;
	int start, end;
	if (n == 0)
		return (1);
	start = l;
	int num = l/5 + 1;
	if (num*5 < r)
		end = num*5;
	else end = r;
	int flag = 0;
	while (flag == 0) {
		int term = end - start + 1;
		if (term >= 3)
			term--;
		sum += (solution(n-1,(num-1)*5 + 1, num*5)%4)*term;
		start = end + 1;
		num++;
		if (num*5 < r)
			end = num*5;
		else {
			end = r;
			flag = 1;
		}
	}
	return (sum);
}

int main(void) {
	cout << solution(2, 4, 17) << '\n';
}