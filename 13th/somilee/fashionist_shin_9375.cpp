#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		map<string, int> a;
		int m;
		cin >> m;
		if(m == 0)
			cout << "0\n";
		else
		{
			for(int j = 0; j < m; j++)
			{
				string w;
				string wear;
				cin >> w >> wear;
				if (a.find(wear) != a.end())
					a.find(wear)->second += 1;
				else
					a.insert({wear, 1});
			}
			int sum = 1;
			for(auto iter = a.begin(); iter != a.end(); iter++)
				sum = sum * (iter->second + 1);
			cout << sum - 1 <<'\n';
		}
	}
}