#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	multiset <int> q;
	int d;
	cin >> d;
	for (int i = 0; i < d; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			string str;
			cin >> str;
			int num;
			if (str == "D")
			{
				cin >> num;
				if (num == 1)
				{
					auto top = q.rbegin();
					if(top != q.rend())
						q.erase(--top.base());
				}
				else
				{
					auto low = q.begin();
					if(low != q.end())
						q.erase(low);
				}
			}
			else if (str == "I")
			{
				cin >> num;
				q.insert(num);
			}
		}
		if (q.empty())
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			cout << *q.rbegin() << " " << *q.begin() << endl; // *q.end() << endl;
		}
		q.clear();
	}
}