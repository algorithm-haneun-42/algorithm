#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset<int> bag;
pair<int, int> jew[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> jew[i].second >> jew[i].first;
	for(int i = 0; i < k; i++)
	{
		int c; cin >> c;
		bag.insert(c);
	}
	sort(jew, jew + n);
	long long sum = 0;
	for(int i = n-1; i >= 0; i--)
	{
		auto mc = bag.lower_bound(jew[i].second);
		if (mc == bag.end())
			continue;
		sum += jew[i].first;
		bag.erase(mc);
	}
	cout << sum;
}