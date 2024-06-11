#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int storey) {
    int answer = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
	pq.push({0, storey});
	while(!pq.empty()) {
		int num = pq.top().first;
		int sto = pq.top().second;
		pq.pop();
		if (sto == 0)
			return (num);
		
		int div = 1;
		while (sto%div == 0) {
			div *= 10;
		}
		pq.push({num + (sto%div)/(div/10), sto - sto%div});
		pq.push({num + 10 - (sto%div)/(div/10), sto - sto%div + div});
	}
    return answer;
}

int main(void) {
	cout << solution(16) << '\n';
	cout << solution(2554) << '\n';
}