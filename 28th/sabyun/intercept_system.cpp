#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxn = 0;
int minn =2147483647; 
void change_map(int *map, double tg, int add, vector<vector<int>> &tgmap)
{
	for (auto a : tgmap)
	{
		double from, to;
		from = a[0];
		to = a[1];
		// cout << from << to;
		maxn = max(maxn, (int)to);
		minn = min(minn, (int)from);
		// cout << endl;
		if (tg !=0 &&from < tg && tg < to)
		{
			for (int i = from; i < to; i++)
				map[i] += add;
		}
		else if (tg == 0)
		{
			for (int i = from; i < to; i++)
				map[i] += add;
		}
	}
}
int solution(vector<vector<int>> targets) {
	int map[100000002] = {0};
	change_map(map,0,1,targets);
	// cout << "max = "<<maxn << " " << minn << endl;
	

	int num = 0;
	while (1)
	{
		int maxtg = 0;
		int maxidx = 0;
		maxtg = 0;
		// maxidx =0;
		for (int i = minn; i < maxn; i++)
		{
			// cout << map[i] << " "<<endl;
			if (maxtg < map[i])
			{
				maxtg = max(maxtg, map[i]);
				maxidx = i;
			}
		}
		if (maxidx != 0)
		{
			change_map(map, maxidx+0.5, -1, targets);
			num++;
		}
		else
			break;
		// cout << "max tg" << maxtg << "maxidx" << maxidx << endl;
	}

	// cout << num << endl;
    return num;
}

int main()
{
	vector <vector<int>> map = {{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4},{200000,999999999}};
	cout << solution(map) << endl;
}