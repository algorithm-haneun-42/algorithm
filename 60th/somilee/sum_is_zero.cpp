#include <iostream>
#include <algorithm>

using namespace std;

int n, m, p;
int b[10001];
int c[20005];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		c[b[i]+10000]++;
	}
	sort(b, b+n);
	long long cnt = 0;
	for(int i = 0; b[i] <= 0 && i+1 < n; i++) {
		int s = i+1;
		int e = n-1;
		while(s < e) {
			if(b[s] + b[e] + b[i] < 0)
				s++;
			else if(b[s] + b[e] + b[i] > 0)
				e--;
			else {
				int s_cnt = 0;
				int e_cnt = 0;
				while(b[s+s_cnt] == b[s] && s+s_cnt < n)
					s_cnt++;
				while(b[e-e_cnt] == b[e] && e-e_cnt > i)
					e_cnt++;
				if(b[s] == b[e])
					cnt += s_cnt * (s_cnt - 1) / 2;
				else
					cnt += s_cnt * e_cnt;
				s += s_cnt;
				e -= e_cnt;
			}
		}
	}
	cout << cnt << endl;
}