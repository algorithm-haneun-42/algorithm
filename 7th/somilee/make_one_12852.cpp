#include <iostream>

using namespace std;

int d[1000005];
int path[1000005];

int main(void)
{
	int n;
	cin >> n;

	d[1] = 0;

	for (int i = 2; i <= n; i ++)
	{
		d[i] = d[i-1] + 1;
		path[i] = i-1;
		if (i % 2 == 0)
		{
			if (d[i] > d[i/2])
				path[i] = i/2;
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			if (d[i] > d[i/3])
				path[i] = i/3;
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}

	cout << d[n] << '\n' << n;
	while (n > 1)
	{
		cout << " " << path[n];
		n = path[n];
	}
}