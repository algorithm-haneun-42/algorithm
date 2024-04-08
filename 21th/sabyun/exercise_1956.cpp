#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int city[405][405];
	int v,e; cin >> v >> e;
	for(int i = 1; i<=v; i++)
	{
		for(int j = 1; j<=v; j++)
		{
			if(i == j)
				city[i][j] = 0;
			else
				city[i][j] = 5000000;
		}
	}
	for (int i = 0; i<e; i++)
	{
		int a,b,c; cin >> a >> b >>c;
		city[a][b] =c;
	}
	for(int k = 1; k <=v; k++)
	{
		for(int i = 1; i <=v; i++)
		{
			for(int j = 1; j <=v; j++)
			{
				if(city[i][j] > city[i][k] + city[k][j])
					city[i][j] = city[i][k] + city[k][j];
			}
		}
	}
	int min_value = 6000000;
	for(int i = 1; i<=v; i++)
	{
		for(int j = 1; j<=v; j++)
		{
			if(city[i][j] != 5000000 && city[i][j] !=0 && city[j][i] != 5000000 && city[j][i] !=0)
			//cout << city[i][j]<< " ";
				min_value = min(min_value,city[i][j]+city[j][i]);
		}
	}
	if(min_value == 6000000)
		cout << "-1 " <<endl;
	else
		cout <<min_value << endl;
}