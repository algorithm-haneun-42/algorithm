#include <stdio.h>

int check_ball(int *num, int *a)
{
	int ball = 0;
	int strike = 0;
	int c_num[3] = {a[0]/100, a[0]%100/10, a[0]%10};
	for(int i = 0; i < 3; i ++)
	{
		for(int j = 0; j < 3; j ++)
		{
			if(num[i] == c_num[j])
			{
				if(i == j)
					strike += 1;
				else
					ball += 1;
			}
		}
	}
	if (strike == a[1] && ball == a[2])
		return(0);
	return (1);
}

int main(void)
{
	int cnt;
	int a[100][3];
	int sum;
	int answer = 0;

	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i ++)
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	for(int i = 1; i <= 9; i ++)
	{
		for(int j = 1; j <= 9; j ++)
		{
			for(int k = 1; k <= 9; k ++)
			{
				if(i != j && j != k && k != i)
				{
					int num[3] = {i, j, k};
					sum = 0;
					for(int t = 0; t < cnt; t ++)
						sum += check_ball(num, a[t]);
					if (sum == 0)
						answer += 1;
				}
			}
		}
	}
	printf("%d\n", answer);
	return (0);
}
