#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
	int n = numbers.size();
	vector<int> re_answer;
	stack<int> st;

	st.push(numbers[n - 1]);
    for (int i = n - 1; i >= 0; i--){
		while(!st.empty()){
			if (st.top() > numbers[i]){
				re_answer.push_back(st.top());
				break;
			}
			st.pop();
		}
		if (st.empty())
			re_answer.push_back(-1);
		st.push(numbers[i]);
	}
	for (int i = n - 1; i >= 0; i--)
		answer.push_back(re_answer[i]);
    return answer;
}

// int main(){
// 	vector<int> numbers = {9, 1, 5, 3, 6, 2};
// 	vector<int> answer = solution(numbers);

// 	for (int i = 0; i < answer.size(); i++){
// 		cout << answer[i] << ' ';
// 	}
// 	return (0);
// }