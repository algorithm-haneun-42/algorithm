#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char> st;
	string s;
	int N;
	int cnt;

	cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (st.empty() || st.top() != s[j])
				st.push(s[j]);
			else if (st.top() == s[j])
				st.pop();
		}
		if (st.empty())
			cnt++;
		cout << "cnt : " << cnt << endl;
		while(!st.empty()) st.pop();
	}
	cout << cnt << endl;
	return (0);
}