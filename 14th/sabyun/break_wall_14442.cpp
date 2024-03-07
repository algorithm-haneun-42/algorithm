#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int map[12][12][11] = {0};
	int vi[12][12][11] = {0};
	int ck[12][12][11] = {-1};
	queue<tuple<int,int,int> > q;
	int dx[4] = {1, 0 , -1, 0};
	int dy[4] = {0, 1 , 0, -1};
	int n , m , k ; cin >> n >> m >> k;
	int world = 0;
	for (int i = 0; i<n; i++)
	{
		string str; cin >> str;
		for(int j = 0; j<m; j++)
			map[i][j] = stoi(str.substr(j,1));
	}

	for (int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}	
		cout << '\n';
	tuple<int, int, int> insert = make_tuple(0, 0, k);
	q.push(insert);
	while(!q.empty())
	{
		int br = k;
		tuple<int,int,int> x_y = q.front(); q.pop();
		for (int l = 0; l<4; l++)
		{
			int x1 = get<0>(x_y) + dx[l]; 
			int y1 = get<1>(x_y) + dy[l];
			int k_x, k_y, k_k; k_x = get<0>(x_y); k_y = get<1>(x_y); k_k = get<2>(x_y);
			if(get<0>(x_y) == m-1 && get<1>(x_y) == n-1)
			{
				cout << "end" <<endl;
					cout << vi[n - 1][m - 1] << endl;
				return 0;
			}
			if (x1 < 0 || y1 <0 || x1 >=m || y1 >= n)
				continue;
			cout << " x = " << x1 << "y = " << y1 << "k = " << k_k <<endl << endl;
			cout << " kx = " << k_x << " ky = " << k_y << " kk = " << k_k <<" vi = " << vi[k_y][k_x]<<endl;
			if(vi[y1][x1] == 0)
			{
				if(map[y1][x1] == 1 && k_k > 0)
				{
					vi[y1][x1] = vi[k_y][k_x] +1;
					insert = make_tuple(x1, y1, k_k-1);
					q.push(insert);
				}
				else if(map[y1][x1] == 0)
				{
					vi[y1][x1] = vi[k_y][k_x] +1;
					insert = make_tuple(x1, y1, k_k);
					q.push(insert);
				}
			}
		}
	}
	cout << "map" << endl;
	for (int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "vi" << endl;
	for (int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cout << vi[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-1"<< endl;
}