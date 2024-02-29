#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int d[10];
int arr[10];

void func(int k)
{
	if (k == m+1)
	{
		for(int i = 1; i <= m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (d[i] != 0 && arr[k-1] <= d[i])
		{
			arr[k] = d[i];
			func(k+1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> d[0];
	for(int i = 1; i < n; i++)
	{
		int a;
		cin >> a;
		for(int j = i - 1; j >= 0; j--)
			if (d[j] == a)
			{
				a = 0;
				break;
			}
		d[i] = a;
	}
	sort(d, d+n);
	func(1);
}