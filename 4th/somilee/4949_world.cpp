#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string str;

	while(1)
	{
		if(!getline(cin, str))
			return (0);
		if(str.compare(".") == 0)
			break;
		stack<char>s;
		int i;
		for(i = 0; str[i]; i ++)
		{
			if (str[i] == '(')
				s.push('(');
			if (str[i] == '[')
				s.push('[');
			if (str[i] == ')')
			{
				if (s.top() == '(')
					s.pop();
				else
				{
					cout << "no\n";
					break;
				}
			}
			if (str[i] == ']')
			{
				if (s.top() == '[')
					s.pop();
				else
				{
					cout << "no\n";
					break;
				}
			}

		}
		if (!str[i])
		{
			if (s.empty())
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
	return (0);
}
