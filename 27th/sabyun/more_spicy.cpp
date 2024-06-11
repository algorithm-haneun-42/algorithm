#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	priority_queue <int,vector<int>,greater<int>> q; 
	for(auto a : scoville)
		q.push(a);
	int num =0;
	while(q.top() < K)
	{
		auto low_num = q.top();q.pop();
		low_num += q.top() *2;q.pop();
		q.push(low_num);
		if(q.size() == 1)
		{
			if(q.top() < K)
				return -1;
		}
		num++;
	}
    return num;
}

int main()
{
	vector<int> scovil = {1, 2, 3, 9, 10, 12};
	int k = 7;
	cout << solution(scovil,k) << endl;
	
}