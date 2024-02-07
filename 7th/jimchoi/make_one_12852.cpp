#include <iostream>
#include <stdio.h>
using namespace std;

int d[1000005];
int pre[1000005];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	if (n == 1)
	{
		cout << 0 << endl << 1;
        return 0;
	}
	for(int i = 4; i <= n; i++)
	{
		d[i] = d[i-1] + 1;
		pre[i] = i-1;
		if (i % 2 == 0 && i != 2)
		{
			if (d[i] > d[i / 2])
			{
				d[i] = d[i / 2] + 1;
				pre[i] = i / 2;
			}
		}
		if (i % 3 == 0 && i != 3)
		{
			if (d[i] > d[i / 3])
			{
				d[i] = d[i / 3] + 1;
				pre[i] = i / 3;
			}
		}
	}
	cout << d[n] <<endl;
	int tmp = n;
	while(tmp > 0)
	{
		cout << tmp << " ";
        tmp = pre[tmp];
	}
	cout << 1 << " ";
}