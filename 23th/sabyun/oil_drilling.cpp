#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
	int vi[502][502] = {0};
	int line[502] = {0};
    int n = land.size();
    int m = land[0].size();
	queue<pair<int ,int> > q;
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(vi[i][j] == 1 || land[i][j]==0)
				continue;
			if(vi[i][j] == 0 && land[i][j] == 1)
			{
				q.push({i,j});
				vi[i][j] = 1;
			}
			int min_x = m;
			int max_x = -1;
			int oil_num = 1;
			while(!q.empty())
			{
				auto q_front = q.front();q.pop();
					for (int k = 0; k < 4; k++)
					{
						int o_x = q_front.second + dx[k];
						int o_y = q_front.first + dy[k];
						if(o_x < 0 || o_x >= m || o_y<0 || o_y>=n)
							continue;
						if(land[o_y][o_x] == 0)
							continue;
						min_x = min(min_x,o_x);
						max_x = max(max_x,o_x);					
						if(vi[o_y][o_x] == 1 || land[o_y][o_x] == 0)
							continue;
						vi[o_y][o_x] = 1;
						q.push({o_y,o_x});
						oil_num++;
					}
			}
			if(max_x == -1)
				max_x = m - 1;
			if(min_x == m)
				min_x = m -1 ;
			if(oil_num == 1)
			{
				min_x = j;
				max_x = j;
			}
			for(int a = min_x; a <= max_x; a++)
			{
				if (a<0)
					continue;
				line[a] += oil_num;
			}
		}
	}
	int ret = 0;
	for(int i = 0; i<m;i++)
	{
		ret = max(line[i], ret);
	}
	return ret;
}
int main()
{
    std::vector<std::vector<int>> inputList = {
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1}
    };
	std::vector<std::vector<int>> inputList2 = {
	{1, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0}, 
	{1, 0, 1, 0, 0, 1}, 
	{1, 0, 0, 1, 0, 0}, 
	{1, 0, 0, 1, 0, 1}, 
	{1, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1}
	};
	std::vector<std::vector<int>> inputList3 = {
	{0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 0}, 
	{0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 1, 0, 0}, 
	{0, 0, 0, 0, 0, 0}, 
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
	};
	std::vector<std::vector<int>> inputList4 = {
	{0, 1},
	{1, 0},
	{1, 0},
	{1, 0}
	};
	vector<vector<int>> land2(500, vector<int>(500, 0));
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			land2[i][j] = (i + j) % 2;
		}
	}
	cout << solution(land2) << endl;
	return 0;
}