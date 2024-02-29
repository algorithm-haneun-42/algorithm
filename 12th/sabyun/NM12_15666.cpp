#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, i, j;
int num[10];
int get_num[10];
int nump[10];
int check[10];

void remove_same_number()
{
	int temp = 0;
	j = 0;
	for(int i = 0; i < n ; i++)
	{
		if(temp != get_num[i])
		{
			num[j++] = get_num[i];
			temp = get_num[i];
		}
	}
}

void print_num(int x)
{
	if (x==m)
	{
		if(x == 0  || (!equal(check,check+m,nump)))
		{
			for(int i= 0; i<m; i++)
				printf("%d ",nump[i]);
			printf("\n");
		}
		copy(begin(nump),end(nump),begin(check));
		return;
	}
	for(int i = 0; i<j;i++)
	{
			if (x>0 &&nump[x-1] > num[i])
				continue ;
			nump[x] = num[i];
			print_num(x+1);
	}
}

int main ()
{
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		nump[i] = 0;
		cin >> get_num[i];
	}
	sort(get_num,get_num+n);
	remove_same_number();
//	for(int i = 0; i<j; i++)
//		printf("num[%d] = %d\n",i,num[i]);
	print_num(0);
	return 0;
}


