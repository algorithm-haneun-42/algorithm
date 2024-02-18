#include <iostream>
#include <algorithm>

using namespace std;

int binarysearch(int n, int a[100000], int trg)
{
	int st = 0;
	int en = n - 1;

	while (st <= en)
	{
		int mid = (st + en) / 2;

		if (a[mid] < trg)
			st = mid + 1;
		else if (a[mid] > trg)
			en = mid - 1;
		else
			return (1);
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int a[100000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k;

		cin >> k;
		cout << binarysearch(n, a, k) << endl;
	}
}