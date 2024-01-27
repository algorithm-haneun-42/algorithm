//입력 함수 getline!!

#include <iostream>
#include <stack>

using namespace std;

int check_pair(stack<char> &brak, char c)
{
	if (brak.empty())	
		return (-1);
	if (c == ')'){
		if (brak.top() == '(')
			brak.pop();
		else
			return (-1);
	}else{
		if (brak.top() == '[')
			brak.pop();
		else
			return (-1);
	}
	return (1);
}

string check_empty(stack<char> brak)
{
	if (brak.empty())
		return ("yes");
	return ("no");
}

int main()
{
	string s;
	string ap;
	stack<char> brak;
	string res;

	while (1)
	{
		getline(cin, s);
		if (s.compare(".") == 0 && s.length() == 1)
			break;
		res = "yes";
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '(' || s[i] == '[')
				brak.push(s[i]);
			else if (s[i] == ')' || s[i] == ']'){
				if (check_pair(brak, s[i]) == -1){
					res = "no";
					break;
				}
			}
		}
		ap = check_empty(brak);
		if (ap == "no")
			res = "no";
		cout << res << endl;
		while (!brak.empty()) brak.pop();
	}
	return (0);
}
