#include <stdio.h>
int countDigits(void);

int k; 
int num[3];

int main()
{
	int n;

	scanf("%d %d", &n, &k);

	num[0]= k / 100; 
	num[1]= (k / 10) - num[0] * 10; 
	num[2]= k % 10;

	int coins[n];

	// for(int i = 0; i < n; i++)
	// 	scanf("%d", &coins[i]);

	printf("%d\n", countDigits());
}
int countDigits(void)
{
	int num = k;
	int len=0;
	while(num > 0)
	{
		len++;
		num = num / 10;
	}
	return len;
}

// void findMinimum(int coins[])
// {
// 	while
// }