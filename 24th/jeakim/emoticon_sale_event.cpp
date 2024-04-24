#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
	int user_n = users.size();
	int emo_n = emoticons.size();
	int total = 0;
	int	num = 0;

	for (int i = 0; i < users.size(); i++){
		int cnt = 0;
		for (int j = 0; j < emoticons.size() && cnt < users[i][1]; j++){
			cout << emoticons[j] << '\n';
			cnt += emoticons[j] * (1 - users[i][0] / 100);
		}
		if (cnt < users[i][1]){
			total += cnt;
			num++;
		}
		cout << cnt << '\n';
	}
    answer.push_back(num);
	answer.push_back(total);
    return answer;
}

int main(){
	vector<vector<int>> users;
	vector<int> emoticons;
	vector<int> answer;

	users = {{40, 10000}, {25, 10000}};
	emoticons = {7000, 9000};

	answer = solution(users, emoticons);

	cout << answer[0] << ' ' << answer[1];

	return (0);
}