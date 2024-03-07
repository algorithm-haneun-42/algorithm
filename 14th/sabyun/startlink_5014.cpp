#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define x first
#define y second

int main() {
	int f ,s ,g , u ,d  ; cin >> f >> s >> g >> u >> d;
	int count = 0;
	int s_count = 0;
	int element = 0;
	int vi[1000010] = {0};
	queue<int> q;
	q.push(s);
	vi[s] = 1;
	while(1)
	{
		if(q.empty())
		{
			cout<< "use the stairs" << endl;
			return 0;
		}
		auto num = q.front(); q.pop();
		if (num == g)
		{
			cout << vi[num]-1 << endl;
			break;
		}
		else
		{
			if(num + u <= f && vi[num+u] == 0)
			{
				vi[num+u] = vi[num] + 1;
				q.push(num + u);
			}
			if(num - d >= 1 && vi[num-d] == 0)
			{
				vi[num -d] = vi[num] +1;
				q.push(num - d);
			}
		}
	}
	return 0;
}
