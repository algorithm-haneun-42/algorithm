#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int pickax = 0;
int point[10][3] = {0};

int find_small(vector<int> picks, vector<string> minerals)
{
	int answer = 0;

	for (int k = 0; k < 3; k++){
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < pickax + 1 && i < minerals.size() / 5 + 1; i++)
			pq.push(point[i][k]);
		for (int i = 0; i < picks[0]; i++){
			answer += pq.top();
			pq.pop();
			cout << answer << endl;
		}
	}
	return (answer);
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
	//dia, iron, stone
	for (int i = 0; i < picks.size(); i++)
		pickax++;
	for (int i = 0; i < pickax + 1 && i < minerals.size();){
		for (int j = i; j < i + 5; j++){
			if ("dia" == minerals[j]){
				point[i][0]++;
				point[i][1] += 5;
				point[i][2] += 25;
			}
			else if ("iron" == minerals[j]){
				point[i][0]++;
				point[i][1]++;
				point[i][2] += 5;
			}
			else if ("stone" == minerals[j]){
				point[i][0]++;
				point[i][1]++;
				point[i][2]++;
			}
		}
		i += 5;
	}
	for (int i = 0; i < pickax + 1 && i < minerals.size() / 5 + 1; i++)
		cout << point[i][0] << " " << point[i][1] << " " << point[i][2] << endl;
	answer = find_small(picks, minerals);
    return answer;
}

int main()
{
	vector<int> picks = {1, 3, 2};
	vector<string> minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};

	cout << solution(picks, minerals);

	return (0);
}