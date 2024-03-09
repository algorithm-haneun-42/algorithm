#include <iostream>

using namespace std;

void fibonacci(int n, int fibo[41][2])
{
	for (int i = 2; i < n + 1; i++){
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	int fibo[41][2];

	cin >> t;
	for (int i = 0; i < 41; i++){
		fibo[i][0] = 0;
		fibo[i][1] = 0;
	}
	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;
	fibonacci(40, fibo);
	for (int i = 0; i < t; i++){
		int zero = 0;
		int one = 0;
		int n;

		cin >> n;
		cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
	}
	return (0);
}
