#include <stdio.h>

int check_digit(long long int i, int n)
{
	char d;
	char before_d = 'l';
	char *hex = "0123456789abcdefghijk";
	while (i > 0)
	{
		d = hex[i%21];
		if (before_d <= d || d > hex[n])
			return (1);
		i = i/21;
		before_d = d;
	}
	return (0);
}

long long int max_hex(int n)
{
	char *hex = "0123456789abcdefghijk";
	long long int sum = 0;
	for(int i = 1; i <= n; i ++)
	{
		if('0' < hex[i] && hex[i] <= '9')
			sum = sum * 21 + hex[i] - '0';
		else
			sum = sum * 21 + hex[i] - 87;
	}
	return (sum);
}

int main(void)
{
	int n;
	int s;
	int num[21];
	long long int sum;
	long long int j;
	int cnt = 0;

	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &num[i]);
	for(long long int i = 1; i <= max_hex(n); i ++)
	{
		if (check_digit(i, n) == 0)
		{
			sum = 0;
			for(int j = i; j > 0; j = j/21)
			{

				sum += num[j%21];
			}
			if(sum == s)
				cnt ++;
		}
	}
	printf("%d\n",cnt);
	return (0);
}
