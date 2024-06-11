#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
	for(int i = 0; i < prices.size(); i++)
	{
		bool push = false;
		for(int j = i+1; j < prices.size(); j++)
		{
			if(prices[i] > prices[j])
			{
				push = true;
				answer.push_back(j-i);
				break;
			}
		}
        if(push == false)
			answer.push_back(prices.size() -1 -i);
	}
    return answer;
}