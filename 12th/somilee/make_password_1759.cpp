#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char p[15];
char arr[15];

int check_possible(char *str)
{
	int cnt = 0;
	for(int i = 0; str[i]; i++)
	{
		if(str[i] == 'a')
			cnt++;
		if(str[i] == 'e')
			cnt++;
		if(str[i] == 'i')
			cnt++;
		if(str[i] == 'o')
			cnt++;
		if(str[i] == 'u')
			cnt++;
	}
	if (cnt > 0 && n - cnt >= 2)
		return (0);
	return (1);
}

void get_password(int k)
{
	if (k == n)
	{
		if (check_possible(arr) == 0)
		{
			for(int i = 0; i < n; i++)
				cout << arr[i];
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (arr[k-1] < p[i])
		{
			arr[k] = p[i];
			get_password(k+1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for(int i = 0; i < m; i++)
		cin >> p[i];
	sort(p, p+m);
	get_password(0);
}