#include <iostream>
#include <cmath>

using namespace std;

long binary_search(long k, long lan[10000], long n, long total)
{
	long start = 0;
	long end = total / n;
	long max_len = 0;

	while (start <= end)
	{
		long mid = (start + end) / 2;
		long cnt = 0;

		if (mid == 0)
			return (max(max_len, (long)1));
		for (int i = 0; i < k; i++)
		{
			cnt += lan[i] / mid;
		}
		if (cnt < n)
			end = mid - 1;
		else
		{
			max_len = mid;
			start = mid + 1;
		}
	}
	return (max_len);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long n, k;
	long lan[10000];
	long total = 0;

	cin >> k >> n;
	for (long i = 0; i < k; i++)
	{
		cin >> lan[i];
		total += lan[i];
	}
	cout << binary_search(k, lan, n, total) << '\n';
	return (0);
}
