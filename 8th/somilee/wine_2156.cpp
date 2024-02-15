#include <iostream>

using namespace std;
int n;
int w[10005];
int b[10005];

int main(void)
{
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> w[i];
	b[1] = w[1];
	b[2] = w[1] + w[2];
	for (int i = 3; i <= n; i++)
	{
		b[i] = max(b[i-3] + w[i-1], b[i-2]) + w[i];
		b[i] = max(b[i], b[i-1]);
	}
	cout << b[n];
}