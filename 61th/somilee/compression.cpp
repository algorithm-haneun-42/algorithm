#include <iostream>

using namespace std;

string str;
int func(int idx) {
	int cnt = 0;
	int flag = 0;
	for(int i = idx; i < str.size(); i++) {
		if(flag || str[i] == ')') {
			if(str[i] == '(')
				flag++;
			else if(str[i] == ')')
				flag--;
			if(flag < 0)
				break;
		}
		else if(str[i] == '(') {
			cnt--;
			cnt += (str[i-1] - '0')*func(i+1);
			flag++;
		}
		else
			cnt++;
	}
	return cnt;
}

int main(void) {
	cin >> str;
	cout << func(0) << endl;
}