#include <iostream>
#include <algorithm>

using namespace std;

int b[500000];
int n;

// int check_end(int num)
// {
// 	int start = 0;
// 	int end = n;
// 	while (start < end)
// 	{
// 		int mid = (start + end) / 2;
// 		if (b[mid] > num)
// 			end = mid;
// 		else
// 			start = mid+1;
		
// 	}
// 	return (start);
// }

// int check_start(int num)
// {
// 	int start = 0;
// 	int end = n;
// 	while (start < end)
// 	{
// 		int mid = (start + end) / 2;
// 		if (b[mid] >= num)
// 			end = mid;
// 		else
// 			start = mid+1;
		
// 	}
// 	return (start);
// }

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
		//cout << check_end(num) - check_start(num) << ' ';
		cout << upper_bound(b, b+n, num) - lower_bound(b, b+n, num) << ' ';
	}
	return (0);
}