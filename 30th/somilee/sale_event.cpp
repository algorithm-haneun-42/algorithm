#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int check_want(vector<string> want, vector<int> number, vector<string> discount, map<string, int> M) {
	for(int i = 0; i < want.size(); i++) {
		auto it = M.find(want[i]);
		if (it == M.end() || it->second < number[i])
			return (0);
	}
	return (1);
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	map<string, int> M;
	for(int i = 0; i < 10; i++) {
		auto it = M.find(discount[i]);
		if (it == M.end())
			M[discount[i]] = 1;
		else
			it->second++;
	}
	int cnt = 0;
	if (check_want(want, number, discount, M) == 1)
		cnt++;
	for(int i = 10; i < discount.size(); i++) {
		auto a = M.find(discount[i]);
		if (a == M.end())
			M[discount[i]] = 1;
		else
			a->second++;
		auto b = M.find(discount[i-10]);
		b->second--;
		if (check_want(want, number, discount, M) == 1)
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