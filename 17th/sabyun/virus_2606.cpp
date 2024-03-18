#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int main(){
ios::sync_with_stdio(0);
queue<int> que[10000];
int vi[10000] = {0};
int n; cin >> n;
int g_num; cin >> g_num;
int count = 0;
	for(int i = 0; i<g_num; i++)
	{
		int a ; cin >> a;
		int b ; cin >>b;
		que[a].push(b);
		que[b].push(a);
	}
	if(que[1].empty())
		{
			cout << count << endl;
			return 0;
		}
	vi[1] = 1;
	while(!que[1].empty())
	{
		int a = que[1].front();
		que[1].pop();
		if(vi[a] == 0)
		{
			count ++;
			vi[a] = 1;
		}
		while (!que[a].empty())
		{
			int b = que[a].front();
			if (vi[b] == 0)
			{
				que[1].push(b);
				que[a].pop();
			}
			else
				que[a].pop();
		}
	}
	cout << count << endl;
}