#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	priority_queue<long, vector<long>, greater<long> > pq;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			long k; cin >> k;
			if (pq.size() < n)
				pq.push(k);
			else
			{
				if (pq.top() < k)
				{
					pq.pop();
					pq.push(k);
				}
			}
		}
	}

	cout << pq.top() << '\n';
}