#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	queue<pair<int,int>> pq;
	for(int i = 0; i < priorities.size(); i++)
		pq.push({priorities[i],i});
	sort(priorities.begin(),priorities.end(),std::greater<int>());
	int i = 0;
	while(1)
	{
		if(pq.front().first >=priorities[0] && pq.front().second == location)
			return i + 1;
		if(pq.front().first >= priorities[0])
		{
			pq.pop();
			priorities.erase(priorities.begin());
			i++;
		}
		else
		{
			pq.push((pq.front()));
			pq.pop();
		}
	}
	return i;
}

int main()
{
	vector<int> arr = {1, 1, 9, 1, 1, 1};
	vector<int> arr2 = {2, 1, 3, 2};


	cout << solution(arr2,2) << endl;
}