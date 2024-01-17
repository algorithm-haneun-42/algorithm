#include <stdio.h>

int main(void)
{
	int n;
	int s;
	int num[20];
	int sum;
	int cnt = 0;

	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i ++)
		scanf("%d", &num[i]);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j <= n - i; j ++)
		{
			sum = 0;
			for (int k = 0; k < i; k ++)
				sum += num[j + k];
			if (sum == s)
				cnt ++;
		}
	}
	printf("%d", cnt);
	return (0);
}
