#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
	if(a.second != b.second)
		return a.second < b.second;
	return a.first >= b.first;
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
	// for(int i = 0; i < n; i++)
	// 	cout << "i = " << i << " " << "won = " << m[i].second << "kg == "<< m[i].first << endl;
	for(int a : bag)
	{
		for(int i = 0; i < n; i++)
		{
			if(m[i].second <= a && m[i].first != 0)
			{
				worth += m[i].first;
				m[i] = make_pair(0,0);
				break;
			}
		}
	}
	cout << worth << endl;
}