
#include <stdio.h>



int countDate(int l, int p, int v);

int main(){
	int i = 1;
	int l;
	int p;
	int v;

	while(1)
	{
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;
		printf("Case %d: %d\n",i, countDate(l, p, v));
		i++;
	}

}

int countDate(int l, int p, int v)
{
	int cycle;
	int daysLeft;
	int day;

	cycle = v / p;
	daysLeft = v % p;

	if (daysLeft > l)
		daysLeft = l;
	
	day = cycle * l + daysLeft;
	return day;
}