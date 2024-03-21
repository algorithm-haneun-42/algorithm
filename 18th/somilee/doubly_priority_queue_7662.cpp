#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		multiset<int> ms;
		int k; cin >> k;
		for(int i = 0; i < k; i++)
		{
			char c; int num; cin >> c >> num;
			if (c == 'I')
				ms.insert(num);
			if (c == 'D' && !ms.empty())
			{
				if (num == -1)
					ms.erase(ms.begin());
				else
					ms.erase(prev(ms.end()));
			}
		}
		if(ms.empty())
			cout << "EMPTY\n";
		else
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
	}
}