#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >>n;
	int map[52][52];
	int goal = 0;
	int p_num = 0;
	vector<pair<int,int> > vec;
	while(1)
	{
		int a; cin >> a;
		int b;cin >> b;
		if(a == -1 && b == -1)
			break;
		map[a][b] = 1;
	}
	queue<int> q;
	int arr[52] = {0};
	for (int j = 1; j < n+1; j++)
	{
		for (int i = 1; i < n+1; i++)
		{
			arr[j] = 1;
			if(map[j][i] == 1)
			{
				q.push(i);
				arr[i] = 1;
			}
		}
		int max_num = 0;
		while(!q.empty())
		{
			int a = q.front();
			q.pop();
			for(int i = 1; i<n+1; i++)
			{
				if(map[a][i] == 1)
				{	
					if(arr[i] == 0)
					{
					q.push(i);
					arr[i] = arr[a] +1;
					}
				}
			}
			int c_num =0;
			for(int i= 1; i<n+1; i++)
			{
				if(arr[i] == 0)
					{
						c_num = 1;
						break;
					}
				max_num =max(arr[i],max_num);
			}
			if(c_num == 0)
				break;
		}
		if(goal > max_num)
			goal = max_num
		vec.push_back({j,max_num});
		fill(arr,arr+52,0);
	}
	int count = 0;
	int goal_arr[52] = {0};
	for (int i = 0; i<n; i++)
	{
		auto a = vec.fornt();
		int x = a.frist();
		int y = a.second();
		if(y == goal)
		{
			goal_arr[count] = x;
			count ++;
		}
	}
	cout << "goal" << goal << << endl;
	cout << count << endl;
	for (int i = 0; i< count; i++)
	{
	cout << goal_arr[i] << " ";
	}
	cout << endl;
}