#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, l;
int a[1005];

int sum_div(int div) {
	int sum = 0;
	for(int i = 0; i <= n; i++) {
		sum += a[i] / div;
		if (a[i] % div == 0)
			sum--;
	}
	return sum;
}

int main(void) {
	cin >> n >> m >> l;
	int i;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	a[n+1] = l;
	sort(a, a+n+1);
	for(int i = 0; i <= n; i++)
		a[i] = a[i+1] - a[i];
	sort(a, a+n+1);
    int st = 1;
    int en = l;
    int result = en;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (sum_div(mid) <= m) {
            result = mid;
            en = mid - 1;
        }
		else
            st = mid + 1;
    }
    cout << result << endl;
    return 0;
}
