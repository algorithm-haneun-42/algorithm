#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int a[1000005];

int main(void)
{
	cin >> f >> s >> g >> u >> d;

	queue<int> Q;
	Q.push(s);
	// a[s] = 1;
	if (s == g)
	{
		cout << '0';
		return (0);
	}

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		int up = cur + u;
		int down = cur - d;
		if (0 < up && up <= f && a[up] == 0)
		{
			if (up == g)
			{
				cout << a[cur]+1;
				return (0);
			}
			Q.push(up);
			a[up] = a[cur] + 1;
		}
		if (0 < down && down <= f && a[down] == 0)
		{
			if (down == g)
			{
				cout << a[cur]+1;
				return (0);
			}
			Q.push(down);
			a[down] = a[cur] + 1;
		}
	}
	cout << "use the stairs";
}