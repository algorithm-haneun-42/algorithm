#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> d;

void	init_d()
{
	for (int i = 1; i < v.size(); i++)
	{
		int l;
		l = v[i] - v[i - 1];
		d.push_back(l);
	}
}

int	check_num(int k)
{
	int num = 0;
	for (int i = 0; i < d.size(); i++)
	{
		num += d[i] / k;
		if (d[i] % k == 0)
			num--;
	}
	return (num);
}

int main()
{
	int n, m, l;

	cin >> n >> m >> l;
	v.push_back(0);
	v.push_back(l);
	for (int i = 0; i < n; i++)
	{
		int k;

		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	init_d();
	sort(d.begin(), d.end());
	int i = 1;
	while (i <= d[d.size() - 1])
	{
		if (check_num(i) == m)
		{
			cout << i << endl;
			break ;
		}
		i++;
	}
	return (0);
}