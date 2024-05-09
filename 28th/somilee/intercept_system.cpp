#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int check_c(vector<vector<int> >c) {
	for(int i = 0; i < c.size(); i++) {
		if (c[i][0] != -1)
			return (1);
	}
	return (0);
}

int solution(vector<vector<int>> targets) {
	vector<int> P;
	vector<vector<int> >c;
	vector<pair<int, int> >len;
	sort(targets.begin(), targets.end());
	for(auto target : targets)
		for(int i = 0; i <2; i++)
			if (find(P.begin(), P.end(), target[i]) == P.end())
				P.push_back(target[i]);
	sort(P.begin(), P.end());
	c.resize(P.size());
	int n = 0;
	for(auto target : targets) {
		int st = distance(P.begin(), lower_bound(P.begin(), P.end(), target[0]));
		int en = distance(P.begin(), lower_bound(P.begin(), P.end(), target[1]));
		len.push_back({st, en});
		for(int i = st; i < en; i++) {
			c[i].push_back(n);
		}
		n++;
	}
	int r_point = 0;
	int cnt = 0;
	// for(int i = 0; i < c.size(); i++) {
	// 	if (c[i].size() > max_len) {
	// 		r_point = i;
	// 		max_len = c[i].size();
	// 	}
	// }
	//cout << '*' << r_point << '\n';
	int k = 3;
	while (k--) {
		int max_len = 0;
		for(int i = 0; i < c.size(); i++) {
			if (c[i].size() > max_len && c[i][0] != -1) {
				r_point = i;
				max_len = c[i].size();
			}
		}
		for(int i = 0; i < c[r_point].size(); i++) {
			int n = i;
			cout << len[n].first << len[n].second << '\n';
			for(int j = len[n].first; j < len[n].second; j++) {
				c[j][0] = -1;
			}
		}
		cout << '\n';
		cnt++;
	}
	return (cnt);
}

int main(void) {
	vector<vector<int>> targets;
	targets = {{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}};
	solution(targets);
}