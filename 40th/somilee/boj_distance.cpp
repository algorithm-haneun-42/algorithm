#include <iostream>
#include <string>

using namespace std;

int n;
string str;
int v[1005];
const int INF = 1e9+10;
int main(void) {
	cin >> n >> str;
	for(int i = 1; i < n; i ++)
		v[i] = INF;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if ((str[i] == 'B' && str[j] == 'O') || (str[i] == 'O' && str[j] == 'J') || (str[i] == 'J' && str[j] == 'B'))
				v[j] = min(v[j], v[i] + (j-i)*(j-i));
		}
	}
	if(v[n-1] == INF)
		cout << -1 << endl;
	else cout << v[n-1] << endl;
	return 0;
}