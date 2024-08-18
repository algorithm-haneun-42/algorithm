#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


string str, e;
stack<char> Q;
int main(void) {
	cin >> str >> e;
	for (int i = 0; i < str.size(); i++) {
		Q.push(str[i]);
		if (Q.top() == e[e.size()-1] && Q.size() >= e.size()) {
			string c;
			for(int j = 0; j < e.size(); j++) {
				c.push_back(Q.top()); Q.pop();
			}
			reverse(c.begin(), c.end());
			if (c != e)
				for(int j = 0; j < c.size(); j++)
					Q.push(c[j]);
		}
	}
	if (Q.empty())
		cout << "FRULA\n";
	else {
		string ans;
		while(!Q.empty()) {
			ans.push_back(Q.top()); Q.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}