#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
	int ord = 0;
	stack<int> s;

	for (int i = 1; i < order.size() + 1; i++){
		if (i == order[ord]){
			ord++;
			answer++;
		}
		else
			s.push(i);
		while (!s.empty() && s.top() == order[ord]){
			ord++;
			answer++;
			s.pop();
		}
	}
    return answer;
}

int main()
{
	vector<int> order = {4, 3, 1, 2, 5};

	cout << solution(order) << endl;

	return (0);
}