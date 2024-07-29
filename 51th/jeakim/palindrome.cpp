#include "iostream"
#include "stack"

using namespace std;

int main()
{
	int	t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string s;
		int len;
		stack<int> st;
		int	rst_begin;
		int rst_end;

		cin >> s;
		len = s.size();
		rst_begin = 0;
		for (int i = 0; i < len / 2; i++)
			st.push(s[i]);
		for (int i = len / 2; i < len; i++)
		{
			if (s[i] == st.top())
				st.pop();
			else if (i == len / 2)
				continue ;
			else
				rst_begin++;
		}
		if (!st.empty())
			rst_begin++;

		while (!st.empty()) st.pop();
		rst_end = 0;
		for (int i = len - 1; i > len / 2 ; i--)
			st.push(s[i]);
		for (int i = len / 2; i >= 0; i--)
		{
			if (st.empty())
			{
				rst_end++;
				break ;
			}
			if (s[i] == st.top())
				st.pop();
			else if (i == len / 2 - 1)
				continue ;
			else
				rst_end++;
		}
		if (!st.empty())
			rst_end++;

		rst_begin = rst_begin > 2 ? 2 : rst_begin;
		rst_end = rst_end > 2 ? 2 : rst_end;
		cout << min(rst_begin, rst_end) << endl;
	}

	return (0);
}