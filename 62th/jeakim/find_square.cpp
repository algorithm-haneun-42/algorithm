#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

// bool	is_palindrome(int n)
// {
// 	string s = to_string(n);
// 	stack<int> st;

// 	if (s.length() % 2 == 0)
// 	{
// 		for (int i = 0; i < s.length() / 2; i++)
// 			st.push(s[i]);
// 		for (int i = s.length() / 2; i < s.length(); i++)
// 		{
// 			if (st.top() != s[i])
// 				return (false);
// 			st.pop();
// 		}
// 	}
// 	else
// 	{
// 		for (int i = 0; i < s.length() / 2; i++)
// 			st.push(s[i]);
// 		for (int i = s.length() / 2 + 1; i < s.length(); i++)
// 		{
// 			if (st.top() != s[i])
// 				return (false);
// 			st.pop();
// 		}
// 	}
// 	return (true);
// }

bool	is_palindrome(int n)
{
	string s = to_string(n);

	int st = 0;
	int en = s.length() - 1;

	while (st <= en)
	{
		if (s[st] != s[en])
			return (false);
		st++;
		en--;
	}
	return (true);
}

bool is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return (false);
	return (true);
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = n; i <= m; i++)
		if (i % 2 != 0 && is_palindrome(i) && is_prime(i))
			cout << i << endl;
	cout << -1 << endl;
	return (0);
}