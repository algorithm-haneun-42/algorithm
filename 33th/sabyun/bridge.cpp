#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue <int> bridge;
	int i = 0;
	int time = 0;
	int tw = 0;
	int out = 0;
	for(int i = 0; i < bridge_length; i++)
		bridge.push(0);
	for(int i = 0; i < truck_weights.size(); i++)
		out+= truck_weights[i];
	while(out != 0)
	{
		tw-=bridge.front();
		out-=bridge.front();
		bridge.pop();
		if(i < truck_weights.size() && tw+truck_weights[i] <= weight)
		{
			bridge.push(truck_weights[i]);
			tw+=truck_weights[i++];
		}
		else
			bridge.push(0);
		time++;
	}
    int answer = time;
    return answer;
}

int main()
{
	vector<int> a = {7,4,5,6};
	cout << solution(2,10,a) << endl;
}
