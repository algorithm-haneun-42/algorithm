#include <iostream>
#include <vector>

using namespace std;

int d, n;
vector<int> oven;
vector<int> dough;

void init()
{
	cin >> d >> n;
	for (int i = 0 ; i < d; i++)
	{
		int k;
		cin >> k;
		oven.push_back(k);
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		dough.push_back(k);
	}
}

int main()
{
	init();

	int h = d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (oven[j] < dough[i] || j == h - 1)
			{
				h = j - 1;
				break ;
			}
		}
	}
	
	cout << h << '\n';

	return (0);
}