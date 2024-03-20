#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;

	cin >> t;
	for (int i = 0; i < t; i++){
		int k;
		cin >> k;
		multiset<int> ms;
		for (int j = 0; j < k; j++){
			char a;
			int n;
			cin >> a >> n;
			if (a == 'D'){
				if(ms.empty())
					continue;
				if (n < 0)
					ms.erase(ms.begin());
				else
					ms.erase(prev(ms.end()));
			}
			else if (a == 'I'){
				ms.insert(n);
			}
		}
		if (ms.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
	}

	return (0);
}
