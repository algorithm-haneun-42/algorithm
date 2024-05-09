#include <iostream>
#include <string>
#include <vector>

using namespace std;

int	far_point(vector<int> v) {
	int i;
	for(i = v.size() - 1; i >= 0; i--) {
		if (v[i] != 0)
			break;
	}
	return (i);
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long ans = 0;
	int dis = 100005;
	while (dis > 0) {
		int d_box = cap;
		int p_box = cap;
		dis = max(far_point(deliveries), far_point(pickups));
		ans += dis + 1;
		for(int i = dis; i >= 0 && (d_box > 0 || p_box > 0); i--) {
			if (deliveries[i] >= d_box) {
				deliveries[i] -= d_box;
				d_box = 0;
			}
			else {
				d_box -= deliveries[i];
				deliveries[i] = 0;
			}
			if (pickups[i] >= p_box) {
				pickups[i] -= p_box;
				p_box = 0;
			}
			else {
				p_box -= pickups[i];
				pickups[i] = 0;
			}
		}
	}
	return (ans*2);
}

int main(void) {
	int cap = 4;
	int n = 5;
	vector<int> deliveries = {0,0,0,0,1};
	vector<int> pickups = {0,0,0,5,0};
	cout << solution(cap, n, deliveries, pickups) << '\n';
}

/*
10312 03040 : 5
10200 03000 : 3
00000 00000

1020102 0201020 : 7
1020100 0201000 : 5
1010000 0100000 : 3
0000000 0000000
*/