#include <stdio.h>

int main(void) 
{
	int n, k;
	int count = 0;
	int sum = 0;
	scanf("%d %d", &n, &k);
	int coins[n];
	
	for(int i=0; i<n; i++)
		scanf("%d", &coins[i]);

	int idx = n-1;
	while(1)
	{
		if(sum == k)
			break;

		else if(coins[idx] > k)
			idx--;

		else
		{
			sum += coins[idx];
			if(sum > k)
			{
				sum -= coins[idx];
				idx--;
			}
			else
				count++;
		}
	}
	printf("%d",count);
}