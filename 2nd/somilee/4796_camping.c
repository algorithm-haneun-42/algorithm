#include <stdio.h>

int main(void)
{
	int i = 1;
	int l;
	int p;
	int v;
	while (1)
	{
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)
			break;
		int s = v / p;
		int r = v % p;
		if (r <= l)
			printf("Case %d: %d\n", i, s * l + r);
		else
			printf("Case %d: %d\n", i, s * l + l);
		i ++;
	}
	return (0);
}
