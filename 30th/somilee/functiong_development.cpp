#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	int day[100];

	for(int i = 0; i < progresses.size(); i++) {
		day[i] = (100 - progresses[i])/speeds[i];
		if ((100 - progresses[i])%speeds[i] != 0)
			day[i]++;
	}
	for(int i = 0; i < progresses.size(); i++)
		cout << day[i] << ' ';
	cout << '\n';
	int cnt = 1;
	for(int i = 0; i < progresses.size(); i++) {
		if (day[i] < day[i+1] || i == progresses.size()-1) {
			answer.push_back(cnt);
			cnt = 1;
		}
		else cnt++;
	}
    return answer;
}

int main(void) {
	vector<int> progresses = {95, 95, 95, 95};
	vector<int> speeds = {4, 3, 2, 1};

	vector<int> ans = solution(progresses, speeds);
	for(int a : ans)
		cout << a << ' ';
}