#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	std::multiset<int> box;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (box.empty())
				cout << "0\n";
			else
			{
				auto a = box.rbegin();
				cout << *a << "\n";
				box.erase(next(a).base());
			}
		}
		else
			box.insert(num);
	}
	return 0;
}