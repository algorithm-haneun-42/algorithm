#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

	int n = users.size();
	sort(users.begin(), users.end());
	for(int i = users[0][0]; i <= users[n-1][0]; i++){
		
	}

    return answer;
}

vector<vector<int>> users = {{40, 10000}, {25, 10000}};
vector<int> emoticons = {7000, 9000}; 
int main(void) {
	solution(users, emoticons);
}