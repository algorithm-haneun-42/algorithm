#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k, n;
	int al[26] = {0};

	al['a' - 'a'] = 1;
	al['n' - 'a'] = 1;
	al['t' - 'a'] = 1;
	al['i' - 'a'] = 1;
	al['c' - 'a'] = 1;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int i = 4; i < s.size() - 4; i++)
		{

		}
	}

	return (0);
}