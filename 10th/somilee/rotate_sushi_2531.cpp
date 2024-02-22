#include <iostream>
#include <queue>

using namespace std;

int s[30005];
int p[3005];

int main(void)
{
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	queue<int> q;
	for (int i = 0; i < k; i++)
	{
		p[i] += 1;
		q.push(i);
	}
	int st = 0;
	int max = 0;
	while (st < n)
	{
		int en = st + (k-1);
		
		
	}	
}