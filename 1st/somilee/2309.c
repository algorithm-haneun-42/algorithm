#include <stdio.h>

int main(void)
{
	int num[9];
	int a;
	int b;
	int sum = 0;

	for(int i = 0; i < 9; i ++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}
	for(int i = 0; i < 9; i ++)
	{
		for(int j = i + 1; j < 9; j ++)
		{
			if (num[i] + num[j] == sum - 100)
            {
                a = num[i];
                b = num[j];
            }
			if (num[i] > num[j])
			{
				int tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 9; i ++)
		if (num[i] != a && num[i] != b)
			printf("%d\n",num[i]);
	return (0);
}
