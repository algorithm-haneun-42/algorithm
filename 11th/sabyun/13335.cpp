#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
queue<int> brige;
queue<int> car;
int main ()
{
	int t;
	int c;
	int l;
	int max = 0;
	int time = 0;
	int car_t;


	scanf("%d %d %d",&c,&l,&t);
	max = t;
	for (int i = 0; i<c; i++)
	{
		scanf("%d",&car_t);
		car.push(car_t);
	}
	for (int i = 0; i<l; i++)
		brige.push(0);
	while(1)
	{
		car_t = brige.front();
		brige.pop();
		max += car_t;
		if (!car.empty() && max - car.front() >= 0)
		{
			car_t = car.front();
			car.pop();
			max -= car_t;
			brige.push(car_t);
		}
		else
			brige.push(0);
		time++;
		if (max == t)
			break;
	}
	printf("%d\n",time);
}
