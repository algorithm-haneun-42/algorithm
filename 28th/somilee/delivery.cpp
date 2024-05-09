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
	int dis = 100005;
    while (dis > 0) {
		int flag = 1;
		int del_box = cap;
		int pick_box = cap;
		for(int i = deliveries.size() - 1; i >= 0; i--) {
			if (flag && (deliveries[i] != 0 || pickups[i] != 0)) {
				dis = i + 1;
				flag = 0;
			}
		}
	}
}

int main(void) {
	int cap = 4;
	int n = 5;
	vector<int> deliveries = {1,0,3,1,2};
	vector<int> pickups = {0,3,0,4,0};
	cout << solution(cap, n, deliveries, pickups) << '\n';
}

10312 03040 : 5
10200 03000 : 3
00000 00000

1020102 0201020 : 7
1020100 0201000 : 5
1010000 0100000 : 3
0000000 0000000