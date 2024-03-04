#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> a;
string passwd;
string name;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		cin >> name >> passwd;
		a.insert({name,passwd});
	}
	for(int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		cout << a.find(str)->second << '\n';
	}
}