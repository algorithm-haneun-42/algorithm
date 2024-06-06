#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >>n;
	int map_list[52][52];

	int goal = n;
	int p_num = 0;
	vector<pair<int,int> > vec;
	map <int, int>  m_map;
	while(1)
	{
		int a; cin >> a;
		int b;cin >> b;
		if(a == -1 && b == -1)
			break;
		map_list[a][b] = 1;
	}
	queue<int> q;
	int arr[52] = {0};
	for (int j = 1; j < n+1; j++)
	{
		for (int i = 1; i < n+1; i++)
		{
			arr[j] = 1;
			if(map_list[j][i] == 1)
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
				if(map_list[a][i] == 1)
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
		goal = min(goal,max_num);
		m_map.insert({j,max_num});
		fill(arr,arr+52,0);
	}
	for (auto map_int = m_map.begin(); map_int != m_map.end(); ++map_int)
	{
		int index = map_int->first;
		int num = map_int->second;
		//if (num > goal)
		//	m_map.erase(index);
	}

	cout << goal << " " << m_map.size() <<endl;
	for(auto a : m_map)
	{
		cout << a.first << " ";
	}
	cout << endl;
}