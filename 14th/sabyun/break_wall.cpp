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
		{
			for(int g = 0; g<k; g++)
				map[i][j][g] = stoi(str.substr(j,1));
		}
	}
	tuple<int, int, int> insert = make_tuple(0, 0, k);
	q.push(insert);
	vi[0][0][world] = 

	for(int )
}