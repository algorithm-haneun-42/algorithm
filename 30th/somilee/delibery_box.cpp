#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int cnt = 0;
	stack<int> keep;
	int j = 0;
	int i = 0;

	while (i < order.size() || j < order.size()){
		if (j < order.size() && i != order[j]) { 
			if ((!keep.empty() && keep.top() != order[j])) {
				if (i == order.size())
					return (cnt);
				keep.push(i++);
			}
			else if (keep.empty())
				keep.push(i++);
			else if (!keep.empty() && keep.top() == order[j]) {
				while(j < order.size() && keep.top() == order[j]) {
					keep.pop();
					cnt++;
					j++;
				}
			}
		}
		else if (j < order.size() && i == order[j]) {
			cnt++;
			i++;
			j++;
		}
	}
	return (cnt); 
}

int main(void) {
	vector<int> order = {1, 2, 4, 3, 5};
	cout << solution(order);
}

