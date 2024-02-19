#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int upper_bound(int n, vector<int> a, int trg)
{
	int start = 0;
	int end = n;

	while (start < end)
	{
		int mid = (start + end) / 2;

		if (a[mid] > trg)
			end = mid;
		else
			start = mid + 1;
	}
	return (start);
}

int lower_bound(int n, vector<int> a, int trg)
{
	int start = 0;
	int end = n;

	while (start < end)
	{
		int mid = (start + end) / 2;

		if (a[mid] >= trg)
			end = mid;
		else
			start = mid + 1;
	}
	return (start);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		cout << upper_bound(n, a, k) - lower_bound(n, a, k) << '\n';
	}

	return (0);
}
