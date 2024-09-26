#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string str;
stack<int> S;
vector<pair<int, int> > V;
vector<string> set;
void makeSets() {
	for(int mask = 0; mask < 1 << V.size(); ++mask) {
		vector<int> del;
		for(int i = 0; i < V.size(); ++i) {
			if(mask & (1 << i)) {
				del.push_back(V[i].first);
				del.push_back(V[i].second);
			}
		}
		sort(del.begin(), del.end(), greater<int>());
		string ans = str;
		if(del.size() > 0) {
			for(int a: del)
				ans.erase(ans.begin()+a);
			set.push_back(ans);
		}
	}
	sort(set.begin(),set.end());
	set.erase(unique(set.begin(), set.end()), set.end());
	for(string a: set)
		cout << a << endl;
}

int main(void) {
	cin >> str;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '(')
			S.push((int)i);
		else if(str[i] == ')') {
			V.push_back({(int)S.top(), i});
			S.pop();
		}
	}
	makeSets();
}