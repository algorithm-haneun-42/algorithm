#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string s;
	stack<char> st;
	int cnt;

	cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			if (s[i + 1] == ')'){
				cnt += st.size();
				i++;
			}
			else{
				st.push('(');
				cnt++;
			}
		}
		else if(s[i] == ')')
			st.pop();
	}
	cout << cnt << endl;
	return (0);
}