#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
	stack <int> st;
	for(int i = 0; i < s.size(); i++)
		(!st.empty() && st.top() == s[i]) ? st.pop(): st.push(s[i]);
	return (st.empty() ? 1 :0 );
}

int main()
{
	string a = "baabaa";
	string b = "bcbc";
	cout << solution(a) << endl;
	cout << solution(b) << endl;

}