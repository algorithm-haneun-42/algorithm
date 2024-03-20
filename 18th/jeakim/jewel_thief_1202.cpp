#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	pair<int, int> jewel[300001];
	multiset<int> bag;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> jewel[i].second >> jewel[i].first;
	sort(jewel, jewel + n);
	for (int i = 0; i < k; i++){
		int c;
		cin >> c;
		bag.insert(c);
	}
	long long point = 0;
	for (int i = n - 1; i >= 0 && !bag.empty(); i--){
		auto it = bag.lower_bound(jewel[i].second);
		if (it == bag.end())
			continue;
		bag.erase(it);
		point += jewel[i].first;
	}
	cout << point << '\n';
	return (0);
}
