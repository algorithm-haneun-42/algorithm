#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> p, int l) {
	queue<pair<int, int> >pq;
	for(int i = 0; i < p.size(); i++)
		pq.push({p[i], i});
	sort(p.begin(), p.end(), greater<int>());
	int cnt = 0;
	while(1) {
		pair<int, int> cur = pq.front(); pq.pop();
		if (cur.first == p[0]) {
			if (cur.second == l)
				return cnt+1;
			cnt++;
			p.erase(p.begin());
		}
		else
			pq.push(cur);
	}
	return 0;
}

int main(void) {
	vector<int> p = {1, 1, 9, 1, 1, 1};
	int l = 0;
	cout << solution(p, l) << endl;
}