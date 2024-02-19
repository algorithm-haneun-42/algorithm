#include <iostream>
#include <algorithm>

using namespace std;

int b[100005];
int n;

int check_exist(int num)
{
	int start = 0;
	int end = n-1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (num < b[mid])
			end = mid-1;
		else if (num > b[mid])
			start = mid+1;
		else
			return (1);
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for(int i=0; i < n; i++)
		cin >> b[i];
	sort(b, b+n);
	int m;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << check_exist(num) << '\n';
	}
	return (0);
}