#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int	far_point(vector<int> d, vector<int> p, int dis) {
	int i;
	for(i = min(dis, (int)d.size() - 1); i >= 0; i--) {
		if (d[i] != 0 || p[i] != 0)
			break;
	}
	return (i);
}

long long get_sum(vector<int> d, vector<int> p) {
	int sum = 0;
	for(int i = 0; i < d.size(); i++) {
		sum += d[i] + p[i];
	}
	return (sum);
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long ans = 0;
	int dis = 100005;
	//long long sum = get_sum(deliveries, pickups);
	while (dis >= 0) {
		int d_box = cap;
		int p_box = cap;
		dis = far_point(deliveries, pickups, dis);
		ans += dis + 1;
		for(int i = dis; i >= 0 && (d_box > 0 || p_box > 0); i--) {
			if (deliveries[i] >= d_box) {
				deliveries[i] -= d_box;
				d_box = 0;
				//sum -= d_box;
			}
			else {
				d_box -= deliveries[i];
				deliveries[i] = 0;
				//sum -= deliveries[i];
			}
			if (pickups[i] >= p_box) {
				pickups[i] -= p_box;
				p_box = 0;
				//sum -= p_box;
			}
			else {
				p_box -= pickups[i];
				pickups[i] = 0;
				//sum -= pickups[i];
			}
		}
	}
	return (ans*2);
}

int main(void) {
	int cap = 99;
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
cp 99
0000000 0000001
0000000 0001000
*/