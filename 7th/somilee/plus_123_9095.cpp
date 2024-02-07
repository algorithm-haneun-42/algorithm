#include <iostream>

using namespace std;

int main(void)
{
	int num;
	cin >> num;

	for (int i = 0; i < num; i ++)
	{
		int n;
		cin >> n;
		
		int d[100000];
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		for (int i = 4; i <= n; i ++)
			d[i] = d[i-1] + d[i-2] + d[i-3];
		cout << d[n] << '\n';
	}
}