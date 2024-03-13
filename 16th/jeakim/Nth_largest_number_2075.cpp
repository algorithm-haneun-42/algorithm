#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> n;
	int i = 0;
	for (; i < n; i++){
		int x;
		cin >> x;
		pq.push(x);
	}
	for (; i < n * n; i++){
		int x;
		cin >> x;
		if (x > pq.top()){
			pq.pop();
			pq.push(x);
		}
	}
	cout << pq.top() << '\n';
	return (0);
}
