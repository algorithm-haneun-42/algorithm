#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	while(n--)
	{
		string str;
		cin >> str;
		stack<char>s;
		int i;
		for(i = 0; str[i]; i ++)
		{
			if (str[i] == 'A')
			{
				if (s.empty() || s.top() == 'B')
					s.push('A');
				else
					s.pop();
			}
			if (str[i] == 'B')
			{
				if (s.empty() || s.top() == 'A')
					s.push('B');
				else
					s.pop();
			}
		}
		if (!str[i] && s.empty())
			cnt ++;
	}
	cout << cnt;
	return (0);
}
