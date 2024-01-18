#include <iostream>
#include <string>

using namespace std;
int main()
{
	int n, sum, ret;
	string tmp;
	cin >> n;
	ret = 0;
	for (int i = 0; i < n; i++) {
		tmp = to_string(i);
		sum = i;
		for (int j = 0; j < tmp.length(); j++) {
			sum += (tmp[j] - '0');
		}
		if (n == sum) {
			ret = i; 
			break;
		}
	}
	cout << ret << endl;
}
