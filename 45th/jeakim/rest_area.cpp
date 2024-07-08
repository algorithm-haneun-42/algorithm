#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> v;

int	find_max()
{
	int	max_idx = 0;
	int max_l = 0;

	for (int i = 1; i < v.size(); i++)
	{
		int l;
		l = v[i] - v[i - 1];
		max_l = max_l > l ? max_l : l;
		max_idx = max_l > l ? max_idx : i - 1;
	}
	return (max_idx);
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
	for (int i = 0; i < m; i++)
	{
		int idx = find_max();
		v.push_back(v[idx] + (v[idx + 1] - v[idx]) / 2);
		sort(v.begin(), v.end());
	}
	// for (int i = 0; i < v.size(); i++)
	// 	cout <<  v[i] << ' ' ;
	// cout << endl;
	int idx = find_max();
	cout << v[idx + 1] - v[idx] << endl;  
	return (0);
}