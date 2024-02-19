#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
int a[10000];

int main(void)
{
	cin >> k >> n;
	for(int i = 0; i < k; i++)
		cin >> a[i];
	sort(a, a+k);
	int min;
	for(min = a[0]; min > 0; min--)
	{
		int sum = 0;
		for(int i=0; i < k; i++)
			sum+= a[i] / min;
		if (sum >= n)
			break;
	}
	cout << min;
}
