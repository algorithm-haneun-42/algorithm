#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

// vector<int> solution(vector<int> sequence, int k) {
//     vector<int> answer;
// 	answer.push_back(0);
// 	answer.push_back(1000);
// 	int end = 0;
// 	int num = 0;

// 	for (int st = 0; st < sequence.size(); st++){
// 		while (end < sequence.size() && num < k){
// 			num += sequence[end];
// 			if (num == k){
// 				break;
// 			}
// 			end++;
// 			cout << num << ' ';
// 		}
// 		if (num == k){
// 			if (end - st < answer[1] - answer[0]){
// 				answer.clear();
// 				answer.push_back(st);
// 				answer.push_back(end);
// 			}
// 		}
// 		num -= sequence[st];
// 		cout << num << endl;
// 	}
//     return answer;
// }

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
	int	num = 0;
	int end = 0;

	answer.push_back(0);
	answer.push_back(1000000);
	for (int st = 0; st < sequence.size(); st++){
		while(end < sequence.size() && num < k){
			num += sequence[end];
			end++;
		}
		if (num == k && end - st <= answer[1] - answer[0]){
			answer.clear();
			answer.push_back(st);
			if (st == sequence.size())
				answer.push_back(end);
			else
				answer.push_back(end - 1);
		}
		num -= sequence[st];
	}
    return answer;
}

int main()
{
	vector<int> answer;
	vector<int> sequence = {1, 1, 1, 2, 3, 4, 5};

	answer = solution(sequence, 5);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	return (0);	
}
