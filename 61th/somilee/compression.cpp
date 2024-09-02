#include <iostream>
#include <stack>

using namespace std;

string str;
stack<int> s;
int main(void) {
	cin >> str;
	int cnt = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == ')') {
			if(cnt != 0) {
				int a = s.top(); s.pop();
				if(a) 
					s.push(-1*(a+10)*cnt);
				else 
					s.push(a+cnt);
			}
			else {
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				if(a < 0) a+= 10;
				if(b < 0) b+= 10;
				s.push(-1*a*b);
			}
			cnt = 0;
		}
		else if(str[i] == '(') {
			s.push(cnt-1);
			s.push(-1*(str[i-1] - 38));
			cnt = 0;
		}
		else
			cnt++; 
		while(s.size() > 1) {
			int a = s.top(); s.pop();
			int b = s.top(); s.pop();
			if (a > 0 && b > 0)
				s.push(a+b);
			else {
				s.push(b);
				s.push(a);
				break;
			}
		}
	}
	if(s.empty())
		cout << str.size() << endl;
	else
		cout << s.top() << endl;
	return 0;
}