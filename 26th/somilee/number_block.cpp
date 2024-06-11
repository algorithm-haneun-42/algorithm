#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int p[50005];
vector<int> answer;
vector<int> solution(long long begin, long long end) {
	//vector<int> answer;
    long long num, div;
    for(num = begin; num <= end; num++) {
        int end_div = (int)sqrt(num);
        bool flag = true;
        for(div = 2; div <= end_div; div++) {
            if (num % div == 0) {
				if ()
                flag = false;
                break;
            }
        }
        if (flag && num != 1)
            answer.push_back(1);
        else
            answer.push_back(num/div);
    }
    return answer;
}

int main(void) {
	long long begin = 100000014;
	long long end = 100000016;
	solution(begin, end);
	// for(long long i = 1; i <= end; i++) {
	// 	cout << i << ' ';
	// }
	cout << '\n';
	for(int n : answer) {
		cout << n << ' ';
	}
}