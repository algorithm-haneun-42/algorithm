#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
	int sum = 0;
	for(int a : picks)
		sum += a;
	vector<vector<string>> mineral;
	for(int i = 0; i < minerals.size(); i += 5) {
		vector<string> tmp;
		for(int j = 0; j+i < minerals.size() && j < 5; j++)
			tmp.push_back(minerals[i+j]);
		mineral.push_back(tmp);
	}
	for (int i = 0; i < mineral.size(); i++)
		sort(mineral[i].begin(), mineral[i].end());
	sort(mineral.begin(), mineral.end());
	for(int i = 0; i < mineral.size() && sum--; i++) {

	}
	for(auto a : mineral) {
		while (picks[2] != 0)
	}
	for(auto a : mineral) {
		for(string b : a)
			cout << b << ' ';
		cout << '\n';
	}
    return 0;
}

int main(void) {
	vector<int> picks;
	vector<string> minerals;

	picks = {1, 3, 2};
	minerals = {"stone", "stone", "stone", "iron", "iron", "diamond", "iron", "stone", "iron"};
	cout << solution(picks, minerals) << '\n';
}