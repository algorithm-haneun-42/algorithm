#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	while(pq.size() > 1 && pq.top() < K){
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		pq.push(a + b * 2);
		answer++;
	}
	if (pq.top() < K)
		return (-1);

    return answer;
}

int main()
{
	vector<int> scoville = {1, 2, 3, 9, 10, 12};
	int k = 7;

	cout << solution(scoville, k) << endl;

	return (0);
}