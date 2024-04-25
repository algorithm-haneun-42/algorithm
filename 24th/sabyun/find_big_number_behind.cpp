#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> ret;
	stack<pair<int,int>> st;
	int n = numbers.size();
	ret.resize(n);
	for(int i = 0; i<n; i++)
	{
		if(st.empty())
		{
			st.push({numbers[i],i});
			continue;
		}
		if(numbers[i] <= st.top().first)
		{
			st.push({numbers[i],i});
			continue;
		}
		while (!st.empty.top().first < numbers[i])
			{
				ret[st.top().second] = numbers[i];
				st.pop();
			}
			else
				break;
		}
	}
	while(!st.empty())
	{
		auto a = st.top();
		ret[a.second] = -1;
		st.pop();
	}
    return ret;
}

int main()
{
	vector<int> map = {
		{2, 3, 3, 5} // [3, 5, 5, -1]
	};
	vector<int> map2 = {
		{9, 1, 5, 3, 6, 2} // [-1, 5, 6, 6, -1, -1]
	};
	vector<int> result = solution(map);
	for(int i = 0; i < map.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	vector<int> result2 = solution(map2);
	for(int i = 0; i < map2.size(); i++)
	{
		cout << result2[i] << " ";
	}
	cout << endl;
}