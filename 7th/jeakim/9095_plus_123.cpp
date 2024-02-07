#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	int table[12];
	table[1] = 1;
	table[2] = 2;
	table[3] = 4;
	for (int j = 4; j < 12; j++)
		table[j] = table[j - 1] + table[j - 2] + table[j - 3];
	cin >> T;
	for (int i = 0; i < T; i++){
		int num;

		cin >> num;
		cout << table[num] << endl;
	}
	return (0);
}
