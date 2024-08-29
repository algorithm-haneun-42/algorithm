#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int g, c, p;
set<int> ans;
int main(void) {
	cin >> g;
	c = sqrt(g);
	p = 1;
	while(c*c - (c-1)*(c-1) <= g) {
		if(c*c - p*p < g)
			c++;
		if(c*c - p*p > g)
			p++;
		else {
			ans.insert(c);
			c++;
			p++;
		}
	}
	if(ans.empty())
		cout << "-1\n";
	else {
		for(int a: ans)
			cout << a << endl;
	}
}