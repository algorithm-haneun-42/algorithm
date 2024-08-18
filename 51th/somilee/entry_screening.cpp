#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long b[100005];

long long check_sum(long long time) {
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += time / b[i];
	return sum;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	sort(b, b+n);
	long long start = 1;
	long long end = 1000000000LL*1000000000LL;
	while (start < end) {
		long long mid = (start + end) / 2;
		if (check_sum(mid) >= m)
			end = mid;
		else
			start = mid+1;
	}
	cout << start << endl;
}