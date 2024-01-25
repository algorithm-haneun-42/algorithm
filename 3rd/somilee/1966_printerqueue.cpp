#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int time;
	cin >> time;

	for(int i = 0; i < time; i ++)
	{
		int n;
		int p;
		int p_num = 0;
		cin >> n >> p;
		queue<int> q;
		for(int k = 0; k < n; k ++)
		{
			int num;
			cin >> num;
			if (k == p)
				p_num = num;;
			q.push(num);
		}
		int sum = 0;
		int j;
		for(j = 0; j < p; j ++)
		{
			if(q.front() > p_num)
			{
				q.pop();
				sum += 1;
			}
			else
			{
				int t = q.front();
				q.pop();
				q.push(t);
			}
		}
		q.pop();
		while(q.front() <= p_num && !q.empty())
			q.pop();
		while(!q.empty())
		{
			if(q.front() >= p_num)
				sum += 1;
			q.pop();
		}
		cout << sum + 1 << "\n";
	}
}
