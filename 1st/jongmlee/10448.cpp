#include <iostream>
#include <set>

using namespace std;
int	main()
{
	int cnt = 0;
	int tri_arr[50];
	for (int i = 1; i < 50; i++) {
		tri_arr[i - 1] = i * (i + 1) / 2;
		if (tri_arr[i - 1] >= 1000) {
			break;
		}
		cnt++;
	}
	set<int> tri_sum_set;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			for (int k = 0; k < cnt; k++) {
				tri_sum_set.insert(tri_arr[i] + tri_arr[j] + tri_arr[k]);
			}
		}
	}
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tri_sum_set.find(tmp) == tri_sum_set.end()) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}
}
