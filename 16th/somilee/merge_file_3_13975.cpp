#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		priority_queue<long, vector<long>,greater<long> > pq;
		int k; cin >> k;
		for(int j = 0; j < k; j++)
		{
			int num; cin >> num;
			pq.push(num);
		}
		long sum = 0;
		while (pq.size() > 1)
		{
			long min1 = pq.top(); pq.pop();
			long min2 = pq.top(); pq.pop();
			sum += min1 + min2;
			pq.push(min1 + min2);
		}
		cout <<  sum << '\n';
	}
}