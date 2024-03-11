#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <deque>
using namespace std;

int z_count;
int o_count;
pair<int,int>save[41];
int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >>t;
	deque<int> store;
	int num;
	save[0] = make_pair(1,0);
	save[1] = make_pair(0,1);
	for (int i = t; i>0;i--)
	{
		cin >> num;
		store.push_back(num);
	}
	num =0;
	while(!store.empty())
	{
		num = store.front();store.pop_front();
		if(save[num].first !=0)
			cout << save[num].first << " " << save[num].second << endl;
		else{
			for(int i = 2; i<=num; i++)
			{
				if (save[i].first ==0)
				{
				z_count = save[i-1].first + save[i-2].first;
				o_count = save[i-1].second + save[i-2].second;
				save[i] = make_pair(z_count,o_count);
				z_count = 0;
				o_count = 0;
				}
			}
			cout << save[num].first << " " << save[num].second << endl;
		}
	}
	return 0;
}
