#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	while(s.length()) {
		int i = 0;
		int len = s.length();
		while(i < len-1) {
			if (s[i] == s[i+1]) {
				s.erase(i,2);
				break;
			}
			i++;
		}
		if (len == s.length())
			return 0;
	}
	return 1;
}

int main(void) {
	cout << solution("baabaa") << endl;
}