#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	string str;

	cin >> str;
	vector<int> v;
	int sum = 0;
	for (int i = 0; str[i]; i ++)
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == '(')
				v.push_back(1);
			else
			{
				for(int j = 0; j < v.size(); j ++)
					v[j] += 1;
				i ++;
			}
		}
		else
		{
			sum += v.back();
			v.pop_back();
		}
	}
	cout << sum;
	return (0);
}
