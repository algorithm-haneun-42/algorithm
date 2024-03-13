#include <iostream>
#include <queue>

using namespace std;

int count_pq(priority_queue<int, vector<int>, greater<int> > pq)
{
	int total = 0;

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

	priority_queue<int, vector<int>, greater<int> > pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		pq.push(k);
	}
	cout << count_pq(pq) << endl;
}
