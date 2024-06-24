#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	long long n, k; cin >> n >> k;
	long long i;
	for(i = 1; i <= 9; i++)
		if (k < i*pow(10, i) - (pow(10, i)-1)/9)
			break;
	long long num = (k - ((i-1)*pow(10,i-1) - (pow(10, i-1)-1)/9));
	long long num1 = (num/i - 1) + pow(10, i-1) + num % i;
	if (num1 > n)
		cout << "-1\n";
	else {
		string nstr = to_string((num/i - 1) + pow(10, i-1) + num % i);
		cout << nstr[(num%i +i - 1)%i] << endl;
	}
	return 0;
}