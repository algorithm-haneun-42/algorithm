#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int check_want(vector<int> number, int M[10]) {
	for(int i = 0; i < number.size(); i++) {
		if (number[i] > M[i])
			return (0);
	}
	return (1);
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int M[10] = {0};
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < want.size(); j++)
			if (discount[i] == want[j])
				M[j]++;
	int cnt = 0;
	if (check_want(number, M) == 1)
		cnt++;
	for(int i = 10; i < discount.size(); i++) {
		for(int j = 0; j < want.size(); j++) {
			if (discount[i] == want[j])
				M[j]++;
			if (discount[i-10] == want[j])
				M[j]--;
		}
		if (check_want(number, M) == 1)
			cnt++;
	}
    return cnt;
}

int main(void) {
	vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
	vector<int> number = {3, 2, 2, 2, 1};
	vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
	cout << solution(want, number, discount);
}