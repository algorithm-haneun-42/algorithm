#include <iostream>
#include <algorithm>

using namespace std;

string str[3];
int b[105][105][105];

int m;
int main(void) {
	cin >> str[0] >> str[1] >> str[2];
	for(int i = 0; i < str[0].size(); i++) {
		for(int j = 0; j < str[1].size(); j++) {
			if (str[0][i] == str[1][j]) {
				for(int k = 0; k < str[2].size(); k++) {
					if (str[0][i] == str[2][k]) {
						b[i+1][j+1][k+1] = b[i][j][k] + 1;
						m = max(m, b[i+1][j+1][k+1]);
					}
				}
			}
		}
	}
	cout << m << endl;
}