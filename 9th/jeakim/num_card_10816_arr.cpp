#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	int a[40000005] = {0};

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		a[k + 10000000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		cout << a[k + 10000000] << '\n';
	}

	return (0);
}
