#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int table[1000001];
	int n;

	cin >> n;
	table[1] = 0;
	for (int i = 2; i <= n; i++){
		table[i] = table[i - 1] + 1;
		if (i % 2 == 0) table[i] = min(table[i], table[i / 2] + 1);
		if (i % 3 == 0) table[i] = min(table[i] , table[i / 3] + 1);
	}
	cout << table[n] << endl;
	return (0);
}