#include <iostream>

using namespace std;

string d;
string str[2];
int b[2][21][101];
int main(void) {
	cin >> d >> str[0] >> str[1];
	for(int i = 0; i < 101; i++) {
		b[0][0][i] = 1;
		b[1][0][i] = 1;
	}
	for(int i = 0; i < d.size(); i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < str[0].size(); k++) {
				if(str[j][k] == d[i])
					b[j][i+1][k+1] = b[(j+1)%2][i][k];
				b[j][i+1][k+1] += b[j][i+1][k];
			}
		}
	}
	cout << b[0][d.size()][str[0].size()]+b[1][d.size()][str[0].size()] << endl;
}