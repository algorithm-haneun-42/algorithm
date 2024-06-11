#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> q;
	for (int i = 0; i < bridge_length; i++)
		q.push(0);
	int i = 0;
	int sum = 0;
	int time = 0;
	while(1)
	{
		sum -= q.front();
		q.pop();
		if (sum + truck_weights[i] <= weight && i < truck_weights.size())
		{
			q.push(truck_weights[i]);
			sum += truck_weights[i];
			i++;
		}
		else
			q.push(0);
		if (sum == 0)
			break;
		time++;
	}
	return (time+1);
}

int main(void) {
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights;
	truck_weights.push_back(7);
	truck_weights.push_back(4);
	truck_weights.push_back(5);
	truck_weights.push_back(6);
	cout << solution(bridge_length, weight, truck_weights);
}
/*
n 트럭갯수              truck_weights.size()
w 최대 w개 트럭 올라갈수   bridge_length
l l무게만큼 가능          weight
*/