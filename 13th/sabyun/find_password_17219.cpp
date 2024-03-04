#include <iostream>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main() {
		map<string, string> pass;
		ios_base::sync_with_stdio(false);
		int get =0;
		int print = 0;
		string site;
		string passwd;
		cin >> get >> print;

		for (int i = get; i>0 ;i--)
		{
				cin >>site >> passwd;
				pass.insert({site,passwd});
		}
		for (int i = print; i>0 ; i--)
		{
			cin >> site;
			auto ret = pass.find(site);
			if (ret != pass.end())
					cout << ret->second <<'\n';
		}
		return 0;
}

