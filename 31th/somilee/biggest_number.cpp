#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
	bool operator() (string a, string b) {
		return (a+b < b+a);
	}
};

string solution(vector<int> numbers) {
	priority_queue<string, vector<string>, cmp > num;
	int zero = 0;
	for(int n : numbers) {
		if (n != 0)
			zero = 1;
		num.push(to_string(n));
	}
	if (zero == 0)
		return ("0");
	string ans;	
	while(!num.empty()) {
		ans += num.top();
		num.pop();
	}
	return (ans);
}

int main(void) {
	vector<int> numbers = {555, 565, 566, 55, 56, 5, 59, 599, 549};
	cout << solution(numbers) << '\n';
}