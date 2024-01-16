#include <stdio.h>

int main()
{
	int arr[9];
	int sum = 0;
	int i = 0;

	while(i < 9)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		i++;
	}
	int tmp;
	for(int i = 0; i < 9; i++)
	{
		for(int j = i; j < 9; j++)
		{
			if(arr[i] > arr[j])
			{
                tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
            }
		}
	}
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(i != j && sum - arr[i] - arr[j] == 100)
			{
                for(int k = 0; k < 9; k++)
				{
					if( k != i && k != j)
						printf("%d\n", arr[k]);
				}
				return 0;
            }
		}
	}

}