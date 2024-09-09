#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool	is_palindrome(int n)
{
	string s = to_string(n);
	stack<int> st;

	if (s.length() % 2 == 0)
	{
		for (int i = 0; i < s.length() / 2; i++)
			st.push(s[i]);
		for (int i = s.length() / 2; i < s.length(); i++)
		{
			if (st.top() != s[i])
				return (false);
			st.pop();
		}
	}
	else
	{
		for (int i = 0; i < s.length() / 2; i++)
			st.push(s[i]);
		for (int i = s.length() / 2 + 1; i < s.length(); i++)
		{
			if (st.top() != s[i])
				return (false);
			st.pop();
		}
	}
	return (true);
}

int main()
{
	int n, m;

	cin >> n >> m;

	vector<bool> prime(m + 1, true);

	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i * i <= m; i++)
		if (prime[i])
			for (int j = i * i; j <= m; j += i)
				prime[j] = false;
	for (int i = n; i <= m; i++)
	{
		if (prime[i])
		{
			if (is_palindrome(i))
				cout << i << endl;
		}
	}
	cout << -1 << endl;
	return (0);
}