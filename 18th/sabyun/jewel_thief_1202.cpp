#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	multiset <int> bag;
	long long worth = 0;
	int n ; cin >> n;
	pair<int, int> m[300002]; 
	int k; cin >> k;

	for (int i = 0; i < n; i++)
	{
		int kg; cin>> kg;
		int won; cin >> won; 
		m[i] = make_pair(won,kg);
	}
	sort(m,m+n);
	for(int i = 0; i < k; i++)
	{
		int a; cin >> a;
		bag.insert(a);		
	}
	for(int i = n-1; i >=0; i--)
		{
			int kg,won; kg = m[i].second; won = m[i].first;
			auto it = bag.lower_bound(kg);
			if(it == bag.end()) continue;
			worth += won;
			bag.erase(it);
		}
	cout << worth << endl;
}