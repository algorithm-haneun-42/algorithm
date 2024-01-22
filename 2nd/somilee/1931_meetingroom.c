#include <stdio.h>

int compare(void *a, void *b)
{
	int *num1 = (int *)a;
	int *num2 = (int *)b;
	if (*num1 > *num2)
		return (1);
	if (*num1 < *num2)
		return (-1);
	if (*num1 == *num2)
	{
		if (*(++num1) > *(++num2))
			return (1);
		else
			return (-1);
	}
	return (0);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int time[n][2];
	for(int i = 0; i < n; i ++)
		scanf("%d %d", &time[i][0], &time[i][1]);
	qsort(time, n, sizeof(time[0]),compare);
	for(int i = 0; i < n; i ++)
		printf("%d %d\n", time[i][0], time[i][1]);
	int cnt;
	int max_cnt = 0;
	int s_time;
	for(int j = 0; j < n; j ++)
	{
		cnt = 0;
		s_time = -1;
		printf("____%d\n", j);
		for(int i = j; i < n; i ++)
		{
			if (s_time <= time[i][0])
			{
				printf("+++%d\n",time[i][0]);
				cnt += 1;
				s_time = time[i][1];
			}
		}
		printf("cnt : %d\n", cnt);
		if (max_cnt <  cnt)
			max_cnt = cnt;
	}
	printf("%d\n", cnt);
}
