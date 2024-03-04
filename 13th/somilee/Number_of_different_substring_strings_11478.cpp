#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
string str;

int main(void)
{
	cin >> str;
	string str1;
	
	for(int term = 1; term <= str.length(); term++)
	{
		for(int i = 0; i + term <= str.length(); i++)
		{
			string str1;
			str1 = str.substr(i, term);
			s.insert(str1);
		}
	}
	cout << s.size() << '\n';
}