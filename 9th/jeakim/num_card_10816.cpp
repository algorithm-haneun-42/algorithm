#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(int n, vector<int> a, int trg)
{
	int start = 0;
	int end = n - 1;
	int cnt = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (a[mid] < trg)
			start = mid + 1;
		else if (a[mid] > trg)
			end = mid - 1;
		else
		{
			int idx = mid;
			while ((idx < n) && a[idx] == trg)
			{
				idx++;
				cnt++;
			}
			idx = mid - 1;
			while (idx >= 0 && a[idx] == trg)
			{
				idx--;
				cnt++;
			}
			break;
		}
	}
	return (cnt);
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
		cout << binary_search(n, a, k) << '\n';
	}

	return (0);
}
