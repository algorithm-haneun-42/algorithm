#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[200005];
int check_k[100000];

int main(void)
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n;   i++)
		cin >> a[i];
	int st = 0;
	int en = 0;
	int	max = -1;
	while (en <= n)
	{
		while (en <= n)
		{
			if (check_k[a[en]] < 2)
				check_k[a[en]]++;
			else
				break ;
			en++;
		}
		if (en - st > max)
			max = en - st;
		check_k[a[st]]--;
		st++;
	}
	cout << max << endl;
}
