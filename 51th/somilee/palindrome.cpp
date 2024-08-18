#include <iostream>
#include <stack>

using namespace std;

int check_pal(string str) {
	int i = 0;
	int j = str.size()-1;
	int flag = 0;
	while (i < j) {
		if (str[i] == str[j]) {
			i++;
			j--;
		}
		else {
			if (flag == 1)
				return 2;
			if (str.size()%2 == 0 && j == str.size()/2) {
				if (flag == 1)
					return 2;
				return 1;
			}
			if ((str[i+1] == str[j]) && (str[i] == str[j-1])) {
				if (str[i+1] == str[j-2]) {
					j--;
					flag = 1;
				}
				else if (str[i+2] == str[j-1]) {
					i++;
					flag = 1;
				}
			}
			else if (str[i+1] == str[j]) {
				i++;
				flag = 1;
			}
			else if (str[i] == str[j-1]) {
				j--;
				flag = 1;
			}
			else
				return 2;
		}
	}
	if (flag == 1)
		return 1;
	return 0;
}

int main(void) {
	int n; cin >> n;
	string str[30];
	for(int i = 0; i < n; i++)
		cin >> str[i];
	for(int i = 0; i < n; i++)
		cout << check_pal(str[i]) << "\n";
}