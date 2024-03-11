#include <iostream>

using namespace std;

#define X first
#define Y second

pair<int, int> d[20];
int a[20];

void print_a(void)
{
	for(int i = 0; i < 20; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int sum(int index)
{
	int sum = 0;
	for (int i = 0; i <= index; i++)
		sum += a[i];
	return (sum);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> d[i].X >> d[i].Y;
	
	int latest = n;
	for(int i = n; i > 0; i--)
	{
		if (d[i].X + i - 1 > n)
			continue;
		if (d[i].X + i - 1 < latest)
		{
			a[d[i].X + i - 1] = d[i].Y;
			latest = i;
		}
		else
		{
			// cout << "i = " << i << " : ";
			// cout << sum(d[latest].X + latest) << " : " << d[i].Y << " : ";
			if (sum(d[latest].X + latest) - 1< d[i].Y)
			{
				for(int j = 0; j < d[latest].X + latest; j++)
					a[j] = 0;
				a[d[i].X + i - 1] = d[i].Y;
				latest = i;
			}
		}
		// print_a();
	}
	cout << sum(15) << '\n';
}