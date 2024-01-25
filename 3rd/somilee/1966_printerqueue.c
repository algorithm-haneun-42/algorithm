#include <stdio.h>

int main(void)
{
	int t_num;
	scanf("%d", &t_num);

	int n;
	int p;
	int j;
	int i_num;
	int c_num;

	for(int i = 0; i < t_num; i ++)
	{
		int flag = 0;
		int sum = 0;
		int same = 0;
		int bigger = 0;
		int num[10] = {0,};
		scanf("%d %d", &n, &p);
		for(j = 0; j < p; j ++)
		{
			scanf("%d",&i_num);
			num[i_num] += 1;
		}
		scanf("%d", &p);
		for(int k = p + 1; k < 10; k ++)
			sum += num[k];
		while(++j < n)
		{
			scanf("%d", &c_num);
			if(c_num == p && flag == 1)
				same += 1;
			if(c_num > p)
			{
				flag = 1;
				bigger += 1;
			}
		}
		if(bigger != 0)
			sum += bigger + same + 1;
		else
			sum += bigger + 1;
		printf("%d\n", sum);
	}
}


			
			


			

		

