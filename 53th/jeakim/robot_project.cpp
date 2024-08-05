#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int x, n;
	vector<int> v;

	cin >> x >> n;
	x *= 10000000;
	for (int i = 0; i < n; i++)
	{
		int l;

		cin >> l;
		v.push_back(l);
	}
	sort(v.begin(), v.end());

	int st, en, flag;
	st = 0;
	en = n - 1;
	flag = 0;
	while (st != en)
	{
		int sum = v[st] + v[en];
		if (sum == x)
		{
			cout << "yes " << v[st] << " " << v[en] << endl;
			flag = 1;
			break ;
		}
		else if (sum < x)
			st++;
		else if (sum > x)
			en--; 
	}
	if (flag == 0)
		cout << "danger" << endl;
	return (0);
}