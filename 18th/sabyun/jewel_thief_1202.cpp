#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
	if(a.first != b.first)
		return a.first > b.first;
	return a.second > b.second;
}
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
	sort(m,m+n,cmp);
	for(int i = 0; i < k; i++)
	{
		int a; cin >> a;
		bag.insert(a);		
	}
	int idx = 0;
	for(int a : bag)
	{
		for(int i = idx; i < n; i++)
		{
			if(m[i].second <= a && m[i].first != 0)
			{
			//	cout << "i = " << i << " " << m[i].second << m[i].first << endl;
				worth += m[i].first;
				idx = i+1;
				break;
			}
		}
	}
	cout << worth << endl;
}