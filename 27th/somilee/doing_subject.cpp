#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> ans;
	vector<pair<string, int> > keep;
    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1]; // 두 번째 string으로 비교합니다.
    });
	int keep_time = 0;
	int c_time = stoi(plans[0][1].substr(0,2))*60 + stoi(plans[0][1].substr(3,2));
	int i = 0;
	while (i < plans.size()) {
		int s_time = stoi(plans[i][1].substr(0,2))*60 + stoi(plans[i][1].substr(3,2));
		if ((c_time < s_time) && !keep.empty()) {
			if (keep[0].second <= s_time - c_time) {
				if (keep.size() > 1) {
					//keep[1].second -= keep[0].second - (s_time - c_time);
					ans.push_back(keep[0].first);
					c_time += keep[0].second;
					keep.erase(keep.begin());
					continue;
				}
			}
			else keep[0].second -= s_time - c_time;
		}
		if (i == plans.size() - 1)
			break;
		int n_time = stoi(plans[i+1][1].substr(0,2))*60 + stoi(plans[i+1][1].substr(3,2));
		if (s_time + stoi(plans[i][2]) <= n_time) {
			ans.push_back(plans[i][0]);
			c_time += stoi(plans[i][2]);
		}
		else {
			keep.push_back({plans[i][0], stoi(plans[i][2]) - (s_time + stoi(plans[i][2]) - n_time)});
			c_time = n_time;
		}
		i++;
	}
	ans.push_back(plans[plans.size()-1][0]);
	for(int i = 0; i < keep.size(); i++) {
		ans.push_back(keep[i].first);
	}
	return (ans);
}

int main(void) {
	vector<vector<string>> plans;
	//plans = {{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}};
	plans ={{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}};
    vector<string> result = solution(plans);
    for (const string& s : result) {
        cout << s << endl;
    }
}
