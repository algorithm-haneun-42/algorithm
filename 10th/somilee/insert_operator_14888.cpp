#include <iostream>

using namespace std;

int n;
int a[11];
//int c[4];
int sum = 0;

void do_calculate(int i, int *c)
{
	if (c[0] <= 0 && c[1] <= 0 && c[2] <= 0 && c[3] <= 0)
	{
		cout << sum <<'\n';
		return ;
	}
	if (c[0] > 0)
	{
		sum = sum + a[i];
		c[0] -= 1;
		do_calculate(i++, c);
	}
	if (c[1] > 0)
	{
		sum = sum - a[i];
		c[1] -= 1;
		do_calculate(i++, c);
	}
	if (c[2] > 0)
	{
		sum = sum * a[i];
		c[2] -= 1;
		do_calculate(i++, c);
	}
	if (c[3] > 0)
	{
		sum = sum % a[i];
		c[3] -= 1;
		do_calculate(i++, c);
	}
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	int c[4];
	for(int i = 0; i < 4; i++)
		cin >> c[i];
	sum = a[0];
	do_calculate(1, c);
}