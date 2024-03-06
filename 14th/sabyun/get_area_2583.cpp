#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define x first
#define y second
int map[502][502] = {0};
bool vi [502][502] = {0};
void make_sq(pair<int,int> x_y, pair<int,int> x1_y1)
{
	for(int i = x_y.x; i<x1_y1.x; i++)
	{
		for(int j = x_y.y; j<x1_y1.y; j++)
		{
			map[j][i] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int,int>> q;
	pair<int,int> x_y;
	pair<int,int> x1_y1;
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	int k_arr[101][5];
	vector<int> print_arr;
	int m, n ,k  =0;
	int big_count, count,pic = 0;
	cin >> m >> n >> k;

	for(int i = 0; i<k; i++)
	{
		cin >> x_y.x >> x_y.y >>x1_y1.x >> x1_y1.y;
		make_sq(x_y,x1_y1);
	}
	for(int i = 0; i<m ;i++)
	{
		for(int j = 0; j<n; j++)
		{
			if (vi[i][j] == 0 && map[i][j] == 0)
			{
				q.push({j,i});
				vi[i][j] = 1;
				pic++;
			}
			else
				continue;
			count =1;
			while(!q.empty())
			{
				pair<int,int> xy = q.front(); q.pop();
				for(int k =0; k<4 ; k++)
				{
					int x1,y1 = 0;
					x1 = xy.x + dx[k];
					y1 = xy.y + dy[k];
					if(x1 <0 || y1 <0 || x1 >= n || y1 >= m)
						continue;
					if (vi[y1][x1] == 1 || map[y1][x1] == 1)
						continue;
					vi[y1][x1] = 1;
					q.push({x1,y1});
					count ++;
				}
			}
			print_arr.push_back(count);
		}
	}
	cout << pic << endl;
	sort(print_arr.begin(),print_arr.end());
	for(int num : print_arr)
	{
		cout << num << ' ';
	}
	cout << endl;

}
