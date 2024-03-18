#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int main(){
ios::sync_with_stdio(0);
queue<int> que[102];
int vi[102] = {0};
int g_num; cin >> g_num;
int count = 0;
for (int j = 0; j<g_num; j++)
{
	for(int i = 0; i<g_num; i++)
	{
		int a; cin >> a;
		if(a == 1)
			que[j].push(i);
	}
}
int arr [102] = {0};
queue <int> q;
for (int i = 0; i<g_num; i++)
{
	for(int num = que[i].size(); num>0; num--)
	{
		int a = que[i].front();
		q.push(a);
		que[i].pop();
		que[i].push(a);
	}
	while(!q.empty())
	{
		int b = q.front();
		q.pop();
		if (arr[b] == 0)
		{
			arr[b] = 1;
			for (int num = que[b].size(); num > 0; num--)
			{
				int a = que[b].front();
				q.push(a);
				que[b].pop();
				que[b].push(a);
			}
		}
	}
	for(int i = 0; i<g_num; i++)
	{
		cout << arr[i] <<" ";
	}
	cout <<endl;
	fill(arr,arr+102,0);
}
}