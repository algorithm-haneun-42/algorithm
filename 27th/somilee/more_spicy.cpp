#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int n = 0;
	for(int s : scoville) {
		pq.push(s);;
	}
	while (pq.top() < K && pq.size() >= 2) {
		n++;
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		pq.push(a + b*2);
	}
	if (pq.size() < 2 && pq.top() < K)
		return (-1);
	return (n);
}

int main(void) {
	vector<int> scoville = {1, 2, 3, 9, 10, 12};
	int K = 7;
	cout << solution(scoville, K) << '\n';
}