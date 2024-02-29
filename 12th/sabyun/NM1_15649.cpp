#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
int n, m, i;
int num[10];
int check[10];

void print_num(int x)
{
	if (x==m)
	{
		for(int i= 0; i<m; i++)
			printf("%d ",num[i]);
		printf("\n");
		return;
	}
	for(int i = 1; i<=n;i++)
	{
		if (check[i] == 0)
		{
		num[x] = i;
		check[i] = 1;
		print_num(x+1);
		check[i] = 0;
		}
	}
}

int main ()
{


	cin >> n >> m;
	for(int i = 0; i<10; i++)
	{
		check[i] = 0;
		num[i] = 0;
	}
	print_num(0);
	return 0;
}


