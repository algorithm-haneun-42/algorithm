#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<vector<int> > V;
	sort(targets.begin(), targets.end());
    int m = 100000005;
	int i = 0;
	while(i < targets.size()){
		if (targets[i][0] < m) {
			V.push_back({targets[i][1], i});
			m = min(m, targets[i][1]);
			i++;
			cout << "min = " << m << '\n';
			for(int j = 0; j < V.size(); j++) {
				cout << V[j][1] << ' ' << V[j][0] << '\n';
			}
			cout << '\n';
		}
		else {
			for(int j = 0; j < V.size(); j++) {
				if (V[j][0] == m)
					V.erase(V.begin()+j);
				sort(V.begin(), V.end());
				m = V[0][0];
			}
		}
	}
	return (0);
}

int main(void) {
	vector<vector<int>> targets;
	targets = {{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}};
	solution(targets);
}