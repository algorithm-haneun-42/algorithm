#include <iostream>

using namespace std;
int	sum, n, s, ret;
int *arr;
void	cal(int idx, int cnt, int start);
int	main()
{
	cin >> n >> s;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cal(i, 0, 0);
	}
	cout << ret << endl;
}

void	cal(int idx, int cnt, int start)
{
	if (cnt == idx) {
		if (sum == s)
			ret++;
		return ;
	}
	for (int i = start; i < n; i++) {
		sum += arr[i];
		cal(idx, cnt + 1, i + 1);
		sum -= arr[i];
	}
}
