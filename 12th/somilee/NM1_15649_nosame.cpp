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

void get_sequence(int num)
{
	if (num_len(num) == m)
		cout << num << '\n';
	for(int i = num%10 + 1; i <= n; i++)
		get_sequence(num*10 + i);
}

int main(void)
{
	cin >> n >> m;

	get_sequence(1);
}