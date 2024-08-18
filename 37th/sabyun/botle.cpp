#include<iostream>
#include<set>

using namespace std;
int main()
{
	set<int> s;
	int a,b,c; cin >> a>> b >>c ;

	s.insert(c);
	if (c-b >0)
		s.insert(c-b);
	if(c-a > 0)
		s.insert(c-a);
	s.insert(b);
	s.insert(a);
	for(auto a : s)
	{
		cout << a << endl;
	}
}