#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ft_permuitation(vector<int> arr_a, int b)
{
	int max_c = -1;

	do {
		int c = 0;
		int i = 0;
		if (arr_a[i] == 0)
			continue ;
		for (int i = 0; i < arr_a.size(); i++)
		{
			c *= 10;
			c += arr_a[i];
		}
		if (c < b)
			max_c = max(c, max_c);
	} while (next_permutation(arr_a.begin(), arr_a.end()));
	return (max_c);
}

int main()
{
	int a, b;
	vector<int> arr_a;

	cin >> a >> b;
	while (a >= 10)
	{
		arr_a.push_back(a % 10);
		a /= 10;
	}
	arr_a.push_back(a);
	sort(arr_a.begin(), arr_a.end());
	cout << ft_permuitation(arr_a, b) << endl;
	return (0);
}