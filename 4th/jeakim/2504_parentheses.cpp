#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
	string s;
	stack<char> st;
	int point;
	int big;
	int small;

	cin >> s;
	big = 0;
	small = 0;
	point = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			st.push(s[i]);
			small++;
		}
		else if (s[i] == '['){
			st.push(s[i]);
			big++;
		}
		else if (s[i] == ')'){
			if (st.empty() || st.top() != '('){
				point = 0;
				break;
			}
			else if(s[i - 1] == '('){
				point += pow(2, small) * pow(3, big);
				st.pop();
				small--;
			}
			else{
				st.pop();
				small--;
			}
		}
		else if (s[i] == ']'){
			if (st.empty() || st.top() != '['){
				point = 0;
				break;
			}
			else if(s[i - 1] == '['){
				point += pow(3, big) * pow(2,  small);
				st.pop();
				big--;
			}
			else{
				st.pop();
				big--;
			}
		}
	}
	if (!st.empty())
		point = 0;
	cout << point << endl;

	return (0);
}
