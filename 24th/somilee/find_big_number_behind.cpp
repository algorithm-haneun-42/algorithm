#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
// vector<int> solution(vector<int> numbers) {
//     vector<int> answer;
//     for(int i = 0; i < numbers.size(); i++){
//         auto b_index = upper_bound(numbers.begin() + i, numbers.end(), numbers[i]);
//         if (b_index == numbers.end())
//             answer.push_back(-1);
//         else
//             answer.push_back(*b_index);
//     }
//     return answer;
// }

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
	for(int i = 0; i <numbers.size(); i++){
		stack<int> num;
		num.push(-1);
		for(int j = numbers.size() - 1; j > i; j--) {
			if (numbers[i] < numbers[j])
				num.push(numbers[j]);
		}
		answer.push_back(num.top());
	}
    return answer;
}

vector<int> numbers = {1, 1, 2, 3, 4, 1};
int main(void) {
    vector<int> result = solution(numbers);
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}