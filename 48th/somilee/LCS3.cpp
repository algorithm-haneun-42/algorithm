#include <iostream>
#include <algorithm>

using namespace std;

string str[3];
int b[105][105][105];

int main(void) {
	cin >> str[0] >> str[1] >> str[2];
	for(int i = 0; i < str[0].size(); i++) {
		for(int j = 0; j < str[1].size(); j++) {
			for(int k = 0; k < str[2].size(); k++) {
				if (str[0][i] == str[1][j] && str[1][j] == str[2][k])
					b[i+1][j+1][k+1] = b[i][j][k] + 1;
				else
					b[i+1][j+1][k+1] = max(max(b[i][j+1][k+1], b[i+1][j][k+1]), b[i+1][j+1][k]);
			}
		}
	}
	cout << b[str[0].size()][str[1].size()][str[2].size()] << endl;
}