#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		pair<int, int> d[45];
		d[0] = {1, 0};
		d[1] = {0, 1};
		for (int i = 2; i <= n; i++)
		{
			d[i].first = d[i-2].first + d[i-1].first;
			d[i].second = d[i-2].second + d[i-1].second;
		}
		cout << d[n].first << ' ' << d[n].second << '\n';
	}
}