#include <stdio.h>

#define INF 0x3fffff
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	char arr[1002];
	int value[1002];
	char boj[3] = "ABC";
	
	for(int i = 0; i < n; i++)
	{
		value[i] = INF;
		scanf("%c",&arr[i]);
	}
	for(int i =0; i < n; i++)
	{
		if(arr[i] == 'B')
			arr[i] = 'A';
		else if(arr[i] == 'O')
			arr[i] = 'B';
		else if(arr[i] == 'J')
			arr[i] = 'C';
	}
	arr[n] = 0;
	char pre = arr[0];
	value[0] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if(pre+1 == arr[j] || (arr[j] == 'A' && pre =='C'))
			{
				if(value[j] > (value[i] + ((j-i)*(j-i))))
				{
					value[j] = (value[i] + ((j-i)*(j-i)));
				}
			}
		}
		if(arr[i+1] != 0)
			pre = arr[i+1];
	}
	if(value[n-1] == INF)
		printf("-1\n");
	else
		printf("%d\n",value[n-1]);
}