#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
	answer.push_back(0);
	answer.push_back(1000);

	for (int st = 0; st < sequence.size(); st++){
		int num = 0;
		int end = st;
		while (end < sequence.size() && num < k){
			num += sequence[end];
			if (num == k){
				if (end - st < answer[1] - answer[0]){
					answer.clear();
					answer.push_back(st);
					answer.push_back(end);
				}
			}
			end++;
		}
	}
    return answer;
}

int main()
{
	vector<int> answer;
	vector<int> sequence = {2, 2, 2, 2, 2};

	answer = solution(sequence, 6);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	return (0);	
}
