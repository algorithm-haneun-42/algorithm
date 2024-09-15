#include <iostream>
#include <regex>

using namespace std;

int main(void) {
	string str; cin >> str;
	regex re("(100+1+|01)+");
	if(regex_match(str, re)) cout << "SUBMARINE\n";
	else cout << "NOISE\n";
	return 0;
}