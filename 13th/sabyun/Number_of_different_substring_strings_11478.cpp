#include <iostream>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
int s_size;
set<string> wd;
string str;

void get_wd(int x)
{
	for (int i = 0; i+x<=s_size; i++)
	{
		string a = str.substr(i,x);
		wd.insert(a);
	}
}

int main() {
				ios::sync_with_stdio(0);
				cin.tie(0);
				cin >> str;
				s_size = str.size();
				for (int i = 1; i<=s_size;i++)
					get_wd(i);
				cout <<wd.size() <<'\n';
				return 0;
}
