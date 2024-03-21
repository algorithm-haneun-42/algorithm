#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


map<int, multiset<int> > b;
multiset<int> level;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int p, l; cin >> p >> l;
		level.insert(l);
		b[l].insert(p);
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++)
	{
		string com; cin >> com;
		if (com == "recommend")
		{
			int num; cin >> num;
			if (num == 1)
				cout << *prev(b[*prev(level.end())].end()) << '\n';
			else
				cout << *(b[*level.begin()].begin()) << '\n';
		}
		if (com == "add")
		{
			int p, l; cin >> p >> l;
			level.insert(l);
			b[l].insert(p);
		}
		if (com == "solved")
		{
			int num; cin >> num;
			for(int i = 1; i <= 100; i++)
			{
				auto it = b[i].find(num);
				if (*it == num)
					b[i].erase(it);
			}
		}
	}
}
// int b[100005];
// multiset<pair<int, int> > level;
// int main()
// {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
	
// 	int n; cin >> n;
// 	for(int i = 0; i < n; i++)
// 	{
// 		int p, l; cin >> p >> l;
// 		b[p] = l;
// 		level.insert(l,p);
// 	}
// 	int m; cin >> m;
// 	for(int i = 0; i < m; i++)
// 	{
// 		string com; cin >> com;
// 		if (com == "recommend")
// 		{
// 			int num; cin >> num;
// 			if (num == 1)
// 			{

// 			}
// 			else
// 				cout << *(b[*level.begin()].begin()) << '\n';
// 		}
// 		if (com == "add")
// 		{
// 			int p, l; cin >> p >> l;
// 			level.insert(l);
// 			b[l].insert(p);
// 		}
// 		if (com == "solved")
// 		{
// 			int num; cin >> num;
// 			for(int i = 1; i <= 100; i++)
// 			{
// 				auto it = b[i].find(num);
// 				if (*it == num)
// 					b[i].erase(it);
// 			}
// 		}
// 	}

// }
/*
6
1000 1
1001 2
19998 78
2667 37
2042 55
123 1
*/