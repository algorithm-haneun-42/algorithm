#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	int box = cap;
	int dist = 0;
	for(int i = n; i > 0; i--)
	{
		if(deliveries[i] == 0 && pickups[i] == 0)
		{
			deliveries.resize(i);
			pickups.resize(i);
			continue;
		}
		


	}
	return answer;
}

int main()
{
	vector<int> deliver = {1, 0, 3, 1, 2};
	vector<int> pickup = {0, 3, 0, 4, 0};

	cout << solution(4,5,deliver,pickup) << endl;
}