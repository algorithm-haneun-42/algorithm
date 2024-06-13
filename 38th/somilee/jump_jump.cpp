#include <iostream>
#include <queue>

using namespace std;

int n;
int A[1005];
priority_queue<pair<int, int> > pq;
int main(void) {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	pq.push({0, 0});
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (cur.first == n - 1) {
			cout << cur.second;
			return 0;
		}
		for(int i = 1; (i <= A[cur.first]) && (cur.first + i < n); i++)
			pq.push({cur.first + i, cur.second + 1});
	}
	cout << "-1";
}