#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int **map;
int ret;
int h_line(int x,int y)
{
	for (int i = 0; i<n; i++)
	{
		if(map[i][y] >= 1)
			return 1;
	}
	return 0;
}

int v_line(int x,int y)
{
	for (int i = 0; i<n; i++)
	{
		if(map[x][i] >= 1)
			return 1;
	}
	return 0;
}
int d1_line(int x,int y)
{
	while (y > 0 && x>0)
	{
		x--;
		y--;
	}
	for (int i = 0; i<n; i++)
	{
		if(map[x+i][y+i] >= 1)
		return 1;
	}
	return 0;
}
int d2_line(int x,int y)
{
	for (int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if (j+i == x + y && map[i][j] >= 1)
				return 1;
		}
	}
	return 0;
}
int is_ok(int x, int y)
{
	if(!h_line(x,y) || !v_line(x,y) || !d1_line(x,y) || !d2_line(x,y))
		return 1;
	return 0;
}
int check_chess(int x, int y)
{
	for(int y1 = 0; y1<n; y1++)
	{
		for(int x1 = 0; x1<n; x1++)
		{
			if((x == x1 ||  y == y1) || ((x -y) == (x1-y1)) ||( (x+y) == (x1 + y1)))
			{
				if(map[y1][x1] != 0)
					return 1;
			}
		}
	}
	return 0;
}
void put_chess(int x, int y)
{
	map[y][x] = -1;
	for(int y1 = 0; y1<n; y1++)
	{
		for(int x1 = 0; x1<n; x1++)
		{
			if((x == x1 ||  y == y1) || ((x -y) == (x1-y1)) ||( (x+y) == (x1 + y1)))
			{
				if(map[y1][x1] >=0)
					map[y1][x1] +=1;
			}
		}
	}
}
void remove_chess(int x, int y)
{
	map[y][x] = 0;
	for(int y1 = 0; y1<n; y1++)
	{
		for(int x1 = 0; x1<n; x1++)
		{
			if((x == x1 ||  y == y1) || ((x -y) == (x1-y1)) ||( (x+y) == (x1 + y1)))
			{
				if (map[y1][x1]>0)
					map[y1][x1] -=1;
			}
		}
	}
}
void print_map()
{
	for(int y1 = 0; y1<n; y1++)
	{
		for(int x1 = 0; x1<n; x1++)
		{
			printf("%d ",map[y1][x1]);
		}
		printf("\n");
	}
}
void chess(int q)
{
	if(q == n)
	{
		ret++;
		return;
	}
	for(int y1 = q; y1<n; y1++)
	{
		for(int x1 = 0; x1<n; x1++)
		{
			if(check_chess(x1,y1)==0)
			{
				put_chess(x1,y1);
			//	print_map();
			//	printf("\n");
				chess(q+1);
				remove_chess(x1,y1);
			}
		}
	}
}

int main ()
{
	cin >> n;

	map = (int **)calloc(sizeof(int *) ,n);
	for(int i = 0; i<n ; i++)
		map[i] = (int*)calloc(sizeof(int) ,n);
	ret = 0;
	//put_chess(3,3);
	//print_map();
	chess(0);
	printf("count = %d\n",ret);

	return 0;
}


