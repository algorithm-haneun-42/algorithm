#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<string, int> name;
//vector<string> name;
vector<int> adj[1001];
int deg[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		string str; cin >> str;
		name.insert({str, i});
		//name.push_back(str);
	}
	//ssort(name.begin(), name.end());

	int m; cin >> m;
	for(int i = 0; i < m; i++)
	{
		string name1, name2; cin >> name1 >> name2;
		int a = name.find(name1)->second;
		int b = name.find(name2)->second;
		adj[b].push_back(a);
		deg[a]++;
	}

	for(int i= 0; i < n; i++)
		cout << deg[i] << ' ';
	cout << '\n';
	vector<int> line[1001];
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(deg[i] == 0)
			q.push(i);
		deg[i] = -1;
	}

	cout << q.front() << ' '; q.pop();
	cout << q.front() << ' '; q.pop();
	cout << '\n';

	queue<int> que;
	while(!que.empty())
	{
		int cur = q.front(); q.pop();
		que.push(cur);
		line[0].push_back(cur);
		for(int i : adj[cur])
		{
			deg[i]--;
			if(deg[i] == 0)
			{
				que.push(i);
				deg[i] = -1;
			}
		}
	}

	//scout << "line=" << line[0].front() << '\n';

	for(int i= 0; i < n; i++)
		cout << deg[i] << ' ';
	cout << '\n';

	
	// int s_flag = 0;
	// int num;
	// for(num = 0; num < 1001; num++)
	// {
	// 	s_flag = 0;
	// 	queue<int> q;
	// 	for(int i = 1; i <= n; i++)
	// 	{
	// 		if(deg[i] == 0)
	// 			q.push(i);
	// 	}
	// 	while(!q.empty())
	// 	{
	// 		int cur = q.front(); q.pop();
	// 		line[num].push_back(cur);
	// 		for(int i : adj[cur])
	// 		{
	// 			deg[i]--;
	// 			if(deg[i] == 0)
	// 				q.push(i);
	// 		}
	// 	}
	// 	for(int i= 0; i < n; i++)
	// 		cout << deg[i] << ' ';
	// 	for(int j = 0; j < n; j++)
	// 	{
	// 		if(deg[j] != 0)
	// 			s_flag = 1;
	// 	}
	// 	cout << "flag=" << s_flag << '\n'; 
	// 	cout << '*' << '\n';
	// 	if(s_flag == 0)
	// 		break;
	// }
	// cout << num << '\n';
}