#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int table[1000001];
	int board[1000001];
	int n;

	cin >> n;
	table[1] = 0;
	board[1] = 0;
	for (int i = 2; i <= n; i++){
		table[i] = table[i - 1] + 1;
		if (i % 2 == 0) {
			board[i] = (table[i] > table[i / 2] + 1 ? i / 2 : i - 1);
			table[i] = min(table[i], table[i / 2] + 1);
		}
		if (i % 3 == 0){
			board[i] = (table[i] > table[i / 3] + 1 ? i / 3 : i - 1);
			table[i] = min(table[i], table[i / 3] + 1);
		}
 	}
	cout << table[n] << endl;
	while (n > 0){
		cout <<  n << ' ';
		n = board[n];
	}
	cout << endl;
	return (0);
}
