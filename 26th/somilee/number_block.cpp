#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> answer;
vector<int> solution(long long begin, long long end) {
	//vector<int> answer;
    long long num, div;
    for(num = begin; num <= end; num++) {
        int end_div = (int)sqrt(num);
        bool is_prime = true;
        for(div = 2; div <= end_div; div++) {
            if (num % div == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime && num != 1)
            answer.push_back(1);
        else
            answer.push_back(num/div);
    }
    return answer;
}

int main(void) {
	long long begin = 1;
	long long end = 11;
	solution(begin, end);
	for(long long i = 1; i <= end; i++) {
		cout << i << ' ';
	}
	cout << '\n';
	for(int n : answer) {
		cout << n << ' ';
	}
}