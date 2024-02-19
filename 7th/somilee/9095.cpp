#include <iostream>

using namespace std;

int plus_123(int num)
{
	int cnt = 0;
	if (num >0)
	{
		cnt += plus_123(num - 1);
		cnt += plus_123(num - 2);
		cnt += plus_123(num - 3);
	}
	if (num == 0)
		cnt ++;
	return (cnt);
}

int main(void)
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++)
	{
		int num;
		cin >> num;
		cout << plus_123(num) << '\n';
	}
}