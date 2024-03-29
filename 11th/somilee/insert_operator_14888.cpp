#include <iostream>

using namespace std;

int n;
int a[11];
int c[4];
int sum = 0;
int max_s;
int min_s;

void do_calculate(int i, int *c)
{
	if (c[0] <= 0 && c[1] <= 0 && c[2] <= 0 && c[3] <= 0)
	{
		//cout << sum <<'\n';
		if (max_s < sum)
			max_s = sum;
		if (min_s > sum)
			min_s = sum;
		return ;
	}
	if (c[0] > 0)
	{
		int temp = sum;
		sum = sum + a[i];
		c[0] -= 1;
		do_calculate(i+1, c);
		c[0] += 1;
		sum = temp;
	}
	if (c[1] > 0)
	{
		int temp = sum;
		sum = sum - a[i];
		c[1] -= 1;
		do_calculate(i+1, c);
		c[1] += 1;
		sum = temp;
	}
	if (c[2] > 0)
	{
		int temp = sum;
		sum = sum * a[i];
		c[2] -= 1;
		do_calculate(i+1, c);
		c[2] += 1;
		sum = temp;
	}
	if (c[3] > 0)
	{
		int temp = sum;
		sum = sum / a[i];
		c[3] -= 1;
		do_calculate(i+1, c);
		c[3] += 1;
		sum = temp;
	}
}

int main(void)
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < 4; i++)
		cin >> c[i];
	sum = a[0];
	max_s = -2147483648;
	min_s = 2147483647;
	do_calculate(1, c);
	cout << max_s << '\n' << min_s;
}