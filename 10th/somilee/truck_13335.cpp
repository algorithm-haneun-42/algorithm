#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int n, w, l;
	cin >> n >> w >> l;

	int t[1000] = {0};
	for (int i = 0; i < n; i++)
		cin >> t[i];

	queue<int> q;
	for (int i = 0; i < w; i++)
		q.push(0);
	int i = 0;
	int sum = 0;
	int time = 0;
	while(1)
	{
		sum -= q.front();
		q.pop();
		if (sum + t[i] <= l && i < n)
		{
			q.push(t[i]);
			sum += t[i];
			i++;
		}
		else
			q.push(0);
		if (sum == 0)
			break;
		time++;
	}
	cout << time + 1 << '\n';
}