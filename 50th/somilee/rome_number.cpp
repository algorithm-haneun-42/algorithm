#include <iostream>
#include <cmath>

using namespace std;

string a, b;
int sum, i, j;
string sign = "IVXLCDM";
int num[7] = {1,5,10,50,100,500,1000};
string s[4][10] = {{"","I","II","III","IV","V","VI","VII","VIII","IX"},
				  {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
				  {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
				  {"", "M","MM","MMM"}};

int a_to_i(string str) {
	int sum = 0;
	for(i = 0; i < str.size(); i++) {
		for(j = 0; j < 8; j++) {
			if(str[i] == sign[j])
				break;
		}
		if((j == 0 || j == 2 || j == 4) && (i != str.size()-1)) {
			if (str[i+1] == sign[j+1]){
				sum += num[j+1] - num[j];
				i++;
				continue;
			}
			else if (str[i+1] == sign[j+2]) {
				sum += num[j+2] - num[j];
				i++;
				continue;
			}
		}
		sum += num[j];
	}
	return sum;
}

string i_to_a(int num) {
	string ans;
	for(int i = 3; i >= 0; i--) {
		ans += s[i][num / (int)pow(10,i)];
		num %= (int)pow(10,i);
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	sum = a_to_i(a) + a_to_i(b);
	cout << sum << endl;
	cout << i_to_a(sum) << endl;
}