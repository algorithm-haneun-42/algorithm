#include <stdio.h>

int main()
{
	int n,k;
	char arr[100005] = {0};
	char oarr[100005] = {0};
	int parr[100005] = {0};
	int oparr[100005] = {0};
	scanf("%d %d",&n ,&k);
	getchar();
	fgets(arr,100005,stdin);
	fgets(oarr,100005,stdin);
	parr[0]=1;
	k = k-1;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j<n; j++)
		{
			if(parr[j] == 1)
			{
				if(j+k >= n || i + k >= n)
				{
					printf("1\n");
					return 0;
				}
				if(j+k < n && arr[j+k] == '1')
					parr[j+k] = 1;
				if(j-k > i && arr[j-k] == '1')
					parr[j-k] = 1;
				if(i+k <n && oarr[i+k] == '1')
					oparr[i+k] =1;
			}
			if(oparr[j] == 1)
			{
				if(j+k >= n || i + k >= n)
				{
					printf("1\n");
					return 0;
				}
				if(j+k < n && oarr[j+k] == '1')
					oparr[j+k] = 1;
				if(j-k > i && oarr[j-k] == '1')
					oparr[j-k] = 1;
				if(i+k <n && arr[i+k] == '1')
					parr[i+k] = 1;
			}
		}
	}
	printf("0\n");
}