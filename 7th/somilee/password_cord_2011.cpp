#include <iostream>

using namespace std;

int main(void)
{
	string n;
	cin >> n;
	if (n[0] == '0')
	{
	cout << '0';
	return (0);
	}
	
	if (!n[1])
	{
		cout << '1';
		return (0);
	}

	if (!n[2])
	{
		if ((n[0] == '1' || n[0] == '2')  && n[1] == '0')
		{
			cout << '1';
			return (0);
		}
	}


	if ((n[0] != '1' && n[0] != '2')  && n[1] == '0')
	{
		cout << '0';
		return (0);
	}
	int d[5000];
	d[0] = 1;
	if ((n[0] == '1' || (n[0] == '2' && n[1] <= '6')) && !(n[0] == '1' && n[1] == '0') && !(n[0] == '2' && n[1] == '0'))
		d[1] = 2;
	else
		d[1] = 1;
	int i = 2;
	while (n[i])
	{
		if ((n[i-1] != '1' && n[i-1] != '2')  && n[i] == '0')
		{
			cout << '0';
			return (0);
		}
		if ((n[i-1] == '1' || (n[i-1] == '2' && n[i] <= '6')) && !(n[i-1] == '1' && n[i] == '0') && !(n[i-1] == '2' && n[i] == '0'))
			d[i] = (d[i-1] + d[i-2]) % 1000000;
		else if (n[i] == '0')
			d[i] = d[i-2];
		else
			d[i] = d[i-1];
		i ++;
	}
	cout << d[i-1];
}