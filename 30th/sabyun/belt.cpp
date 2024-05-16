#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<int> car) {
	stack <int> sub;
	stack <int> belt;
	stack <int> order;

	int num = car.size();
	int answer = 0;
	int i = 1;
	for (int i = car.size() - 1; i >= 0; i--)
		order.push(car[i]);
	while (1)
	{
		if (!order.empty() && order.top() == i)
		{
			if(i <= num)
			{
				i++;
				order.pop();
				answer++;		
			}
		}
		else if (!sub.empty() && !order.empty() && sub.top() == order.top())
		{
			sub.pop();
			order.pop();
			answer++;
		}
		else if (i <= num)
		{
			sub.push(i);
			i++;
		}
		else{
			break;
		}
	}
    return answer;
}

int main()
{
	vector<int> arr = {4, 3, 1, 2, 5};
	vector<int> arr1 = {5,4,3,2,1};
	vector<int> arr2 = {3,2,1,5,7,6,4};
	vector<int> arr3 = {3,2,4,9,6,5,8,7,3,1};

	

	cout << solution(arr3) << endl;
}