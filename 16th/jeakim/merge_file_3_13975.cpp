#include <iostream>
#include <queue>

using namespace std;

long count_num(priority_queue<int, vector<int>, greater<int> > pq)
{
	long total = 0;

	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		total += a + b;
		pq.push(a + b);
	}
	return (total);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		priority_queue<int, vector<int>, greater<int> > pq;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++){
			int x;
			cin >> x;
			pq.push(x);
		}
		cout << count_num(pq) << '\n';
	}

	return (0);
}
