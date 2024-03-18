#include <iostream>
#include <queue>

using namespace std;
int b[105][105];
int v[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> b[i][j];
	queue<int> Q;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(b[i][j] == 1)
			{
				Q.push(j);
				v[i][j] = 1;
			}
		while(!Q.empty())
		{
			int cur = Q.front(); Q.pop();
			for(int j = 0; j < n; j++)
			{
				int c = b[cur][j];
				if(v[c][j] == 0)
				{
					Q.push(c);
					v[c][j] = 1;
				}
			}
		}
	}
	cout << '\n';
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}