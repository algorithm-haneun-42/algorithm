#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <deque>
using namespace std;

int l_day;
int total_cost;
int cost;
pair<int,int>plan[16];
void day_in(int n)
{
	for(int i = l_day; i>0 ; i--)
	{
		if (i+plan[i].first > l_day+1 )
			continue;
		cost+=plan[i].second;
		l_day = i-1;
	}
}
int main()
{
	cin >>l_day;
	fill(begin(plan), end(plan), make_pair(0, 0));
	for (int i = 1; i<=l_day; i++)
	{
		int t; cin >> t;
		int p; cin >> p;
		plan[i] = make_pair(t,p);
	}
	day_in(l_day-1);
	cout << "total cost = " << cost << endl;
}