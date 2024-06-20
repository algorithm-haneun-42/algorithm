#include <stdio.h>

int arr[102][102];
int pnum[102];
int n;
int t;
int a,b;

void runp(int num)
{
	if(arr[num][0] >= 0)
	{
		for(int i = 1;  arr[num][i] > 0 && i <= pnum[num]; i++)
		{
			if(arr[arr[num][i]][0]>= 0)
				return;
		}
		arr[num][0]-=1;
		if(arr[num][0] == 0)
			n--;
	}
}
int main()
{

	scanf("%d",&n);
	getchar();
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d",&a,&b);
		arr[i][0] = a;
		pnum[i] = b;
		for(int j = 0; j < b; j++)
			scanf("%d",&arr[i][j+1]);
	}
	int i = 1;
	t = n;
	while(1)
	{
		for(int j = 1; j <= t; j++)
			runp(j);
		if(n == 0)
			break;
		i++;
	}
	printf("%d",i);
}