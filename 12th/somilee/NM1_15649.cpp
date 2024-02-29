#include <iostream>

using namespace std;

int m, n;

int num_len(int num)
{
	int len = 0;
	while(num > 0)
	{
		num = num/10;
		len++;
	}
	return (len);
}
int check_digit(int num, int i)
{
	for(int div = 10000000; div > 0; div /= 10)
		if (num/div == i)
			return (1);
	return (0);
}

void get_sequence(int num)
{
	if (num_len(num) < m)
		for(int i = 1; i <= n; i++)
			if (check_digit(num, i) == 0)
					get_sequence(num*10 + i);
	if (num_len(num) == m)
		cout << num << '\n';
	else
		return;	
}

int main(void)
{
	cin >> n >> m;

	get_sequence(0);
}