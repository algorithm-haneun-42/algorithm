#include <iostream>
#include <deque>

using namespace std;

int b[20][20];

int main(void)
{
	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> b[i][j];
	
	int min = 2147483647;

	deque<int> d;
	while(d.size() <= n/2)
	{}
}