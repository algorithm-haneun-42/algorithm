#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> q;
	for(int i = 1; i <= n; i ++)
		q.push(i);

	while( q.size() > 1)
	{
		q.pop();
		int t = q.front();
		q.pop();
		q.push(t);
	}

	int f = q.front();
	cout << f << "\n";
}