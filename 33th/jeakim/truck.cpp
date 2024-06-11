#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
	int cw = 0;
	queue<int> q;
	int time[10000] = {0};
	int	i = 0;

	q.push(i);
	while (int i = 1; i < truck_weights.size(); i++){
		if (cw < weight && q.size() < bridge_length){
			q.push(i);
			time[i]++;
		}
		if (time[q.front()] > bridge_length)
			q.pop();
		answer++;
	}
    return answer;
}