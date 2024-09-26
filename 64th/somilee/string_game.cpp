#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
string str;
int main(void) {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str >> m;
		vector<int> ans;
		vector<int> V[26];
		for(int i = 0; i < str.size(); i++) {
			V[str[i] - 'a'].push_back(i);
			int v_size = V[str[i]-97].size();
			if(v_size >= m) {
                int start_idx = V[str[i] - 'a'][v_size - m];
				ans.push_back(i - start_idx + 1);
			}
		}
		if(ans.size() < 1)
			cout << "-1\n";
		else {
			sort(ans.begin(), ans.end());
			cout << ans[0] << ' ' << ans[ans.size()-1] << endl;
		}
	}
}