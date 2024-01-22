#include <stdio.h>

int main(void)
{
	int num;
	int won;
	scanf("%d %d", &num, &won);
	
	int coin[num];
	for(int i = 0; i < num; i ++)
		scanf("%d", &coin[i]);

	int div;
	int cnt = 0;
	for(int i = num - 1; i >= 0; i --)
	{
		div = won / coin[i];
		won %= coin[i];
		if (div > 0)
			cnt += div;
		div = 0;
	}
	printf("%d\n",cnt);
}
