#include <iostream>
#include <set>
using namespace std;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
set<int> box;
int n; cin >> n;
for (int i = 0 ; i < n; i++)
{
	for(int j = 0; j < n; j++)
	{
		int a; cin >> a;
		if(box.size() < n)
			box.insert(a);
		else{
			auto num = box.begin();
			if(a > *num)
				{
					box.erase(num);
					box.insert(a);
				}
		}
	}
}
cout << *box.begin() << '\n';
}