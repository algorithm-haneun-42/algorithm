#include <iostream>

using namespace std;

string d;
string str[2]
int b[21][2][101];
int main(void) {
	cin >> d >> str[0] >> str[1];
	for(int i = 0; i < 101; i++) {
		b[0][0][i] = 1;
		b[0][1][i] = 1;
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 1; j <= d.size(); j++) {
			for(int k = 0; i < str[0].size(); k++) {
				if(str[(i+j)%2][k] == d[j]) {
					b[t ]
				}
			}
		}
	}
}  ~