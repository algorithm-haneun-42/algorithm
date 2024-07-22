#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int m[4];
int b[16][5];
int arr[16];
int isused[16];
int cnt = 0xfffffff;
stack<vector<int> > S;

void func(int k) {
	int flag = 0;
	for(int i = 0; i < 4; i++) {
		int sum = 0;
		for(int j = 0; j < k; j++) {
			sum += b[arr[j]][i];
		}
		if (sum < m[i])
			flag = 1;
	}
	if (flag == 0) {
		int cost = 0;
		for(int i = 0; i < k; i++)
			cost += b[i][4];
		if (cnt > cost) {
			cnt = cost;
			vector<int> a;
			for(int i = 0; i < k; i++)
				a.push_back(arr[i]);
			S.push(a);
		}
		return;
	}
	if (k == n) {
		cnt = -1;
		return;
	}
	for(int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k+1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	cin >> n;
	for(int i = 0; i < 4; i++) {
		cin >> m[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> b[i][j];
		}
	}
	func(0);
	if (cnt == -1) {
		cout << cnt << endl;
		return 0;
	}
	cout << cnt << endl;
	for(int a : S.top())
		cout << a+1 << ' ';
	cout << endl;
}