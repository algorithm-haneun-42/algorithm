
#include <iostream>

int wine[10001];
int drink[10001];

int main(void)
{
	int n;

	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> wine[i];
	drink[1] = wine[1];
	drink[2] = wine[1] + wine[2];
	int	x = wine[1] + wine[2];
	int	y = wine[1] + wine[3];
	int z = wine[2] + wine[3];
	if (x >= y && x >= z)
		drink[3] = x;
	else if (y >= x && y >= z)
		drink[3] = y;
	else if (z >= x && z >= y)
		drink[3] = z;
	for (int i = 4; i <= n; i++)
	{
		int	a = drink[i - 1];
		int	b = drink[i - 2] + wine[i];
		int	c = drink[i - 3] + wine[i - 1] + wine[i];
		if (a >= b && a >= c)
			drink[i] = a;
		else if (b >= a && b >= c)
			drink[i] = b;
		else if (c >= a && c >= b)
			drink[i] = c;
	}
	std::cout << drink[n] << std::endl;
	return (0);
}
