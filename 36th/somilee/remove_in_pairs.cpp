#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int solution(string s) {
	stack<char> q1, q2;
	for(int i = 0; i < s.length(); i++)
		q1.push(s[i]);
	while(!q1.empty()) {
		if (!q2.empty() && q1.top() == q2.top()) {
			q1.pop(); q2.pop();
		}
		else {
			q2.push(q1.top());
			q1.pop();
		}

	}
	if (!q2.empty())
		return 0;
	return 1;
}

int main(void) {
	cout << solution("cdcd") << endl;
}